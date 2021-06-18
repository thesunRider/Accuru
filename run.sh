
if test -f lex.yy.c; then
   rm lex.yy.c
fi
flex $1
gcc lex.yy.c -lfl
./a.out
