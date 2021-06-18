echo '__________________FINAL_______________________'
cat out.txt
echo '______________________________________________'
echo Press any key to execute code..
read
cp out.txt ~/xsm_expl/tmp/out.xsm
xsm -l tmp/library.lib -e tmp/out.xsm --debug
