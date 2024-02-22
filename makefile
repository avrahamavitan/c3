all:Strlist

Strlist: Strlist.o main.o
	gcc -Wall -g -o Strlist Strlist.o main.o -lm

Strlist.o:Strlist.h
main.o:Strlist.h

clean:
	rm -f *.a *.o Strlist 