{ echo -ne '0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\nMOV SP, 4121\n'; cat out.txt; }>out.tn
rm out.txt
mv out.tn out.txt
echo 'INT 10'>>out.txt
echo '__________________FINAL_______________________'
cat out.txt
echo '______________________________________________'
echo Press any key to execute code..
read
cp out.txt ~/xsm_expl/tmp/out.xsm
xsm -l tmp/library.lib -e tmp/out.xsm --debug
