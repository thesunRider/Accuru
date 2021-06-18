yacc -d $1'.y'
flex $1'.l'
gcc -o a.out y.tab.c lex.yy.c -g -no-pie -static
./a.out
echo finished yacc and lex,press any key to continue
read
