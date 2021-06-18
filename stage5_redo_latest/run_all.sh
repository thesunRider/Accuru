./cleanup.sh 
clear 
./crun.sh exptree
echo -ne '\n\n'
echo '___________________INPUT______________________'
cat inp.txt
echo '______________________________________________'
echo '_______________COMMENTED________________'
cat out.txt
echo '______________________________________'
./run.sh strip_comments.l
echo 
rm out.txt
mv out2.txt out.txt
echo '_________________PASS1 COMMENTREMOVAL_______________'
cat out.txt
echo '____________________________________________________'
echo Press any key to continue to label removal....
echo
read
{ echo -ne '0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\nMOV SP, 4096\nMOV BP, 4096\n'; cat out.txt; }>out.tn
rm out.txt
mv out.tn out.txt
echo -ne ':-103\nINT 10'>>out.txt
flex label_strip.l &&gcc -o a.out lex.yy.c -lfl -g -no-pie -static
./a.out
flex label_strip_pass2.l &&gcc -o a.out lex.yy.c -lfl -g -no-pie -static
./a.out

rm out.txt
mv striped3.txt out.txt
echo
echo "_________________PASS3 LINESTRIP_______________________"
cat out.txt
echo "_______________________________________________________"
./write_headers.sh
