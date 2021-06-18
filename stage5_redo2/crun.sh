yacc -d $1'.y'
flex $1'.l'
gcc -o a.out y.tab.c lex.yy.c -g
./a.out
