wordcount: wordcount.o bst.o
	gcc -o wordcount wordcount.o bst.o

wordcount.o: wordcount.c bst.h
	gcc -c wordcount.c

bst.o: bst.c bst.h
	gcc -c bst.c