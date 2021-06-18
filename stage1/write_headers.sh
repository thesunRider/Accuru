{ echo -ne '0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n'; cat out.txt; }>out.tn
rm out.txt
mv out.tn out.txt
cp out.txt ~/xsm/xsm_expl/tmp/out.xsm
cp library.lib ~/xsm/xsm_expl/tmp
xsm -e tmp/out.xsm --debug