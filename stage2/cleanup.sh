
if test -f y.tab.c; then
rm y.tab.c
rm y.tab.h
fi

if test -f lex.yy.c; then
rm lex.yy.c
fi

if test -f a.out; then
rm a.out
fi

if test -f out.c; then
rm out.c
fi

if test -f out.txt; then
rm out.txt
fi


echo Done Cleaning!
