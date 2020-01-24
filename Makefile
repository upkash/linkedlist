linkedlist: linkedlist.o main.o
	gcc -o linkedlist linkedlist.o main.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c -std=c99 -Wall linkedlist.c

#linkedlist_test.o: linkedlist_test.c linkedlist.h 
main.o: main.c linkedlist.h
	gcc -c -std=c99 -Wall main.c
clean:
	rm -f linkedlist main.o linkedlist.o


