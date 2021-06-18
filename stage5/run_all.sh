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
echo Press any key to continue....
echo
read
flex strip_label.l 
gcc lex.yy.c 
./a.out 
rm out.txt
mv out2.txt out.txt
echo '_________________PASS2 LABELREMOVAL_______________'
cat out.txt
echo '__________________________________________________'

flex strip_emptyline.l 
gcc lex.yy.c 
./a.out 
rm out.txt
mv out2.txt out.txt
echo
echo "_________________PASS3 LINESTRIP_______________________"
cat out.txt
echo "_______________________________________________________"
read
./write_headers.sh
