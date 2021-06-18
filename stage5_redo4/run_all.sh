yacc -d $1'.y'
flex $1'.l'
gcc -o a.out y.tab.c lex.yy.c -g -no-pie
./a.out

flex label.l
gcc lex.yy.c
./a.out