
if test -f lex.yy.c; then
   rm lex.yy.c
   rm a.out
fi
flex $1
gcc lex.yy.c -lfl

./a.out

