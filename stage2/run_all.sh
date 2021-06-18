./cleanup.sh 
clear 
./crun.sh exptree
echo -ne '\n\n'
cat inp.txt
echo 
./run.sh strip_comments.l
echo 
rm out.txt
cp out2.txt out.txt
cat out.txt
echo
./write_headers.sh
