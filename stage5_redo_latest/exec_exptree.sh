flex label_strip.l &&gcc -o a.out lex.yy.c -lfl -g -no-pie -static
./a.out
flex label_strip_pass2.l &&gcc -o a.out lex.yy.c -lfl -g -no-pie -static
./a.out

