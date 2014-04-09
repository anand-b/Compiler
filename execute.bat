flex c.l
bison -dy c.y
gcc lex.yy.c y.tab.c -o c
c source.txt