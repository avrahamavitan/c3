all:StrList

StrList: Strlist.o main.o
	gcc -Wall -g -o StrList Strlist.o main.o -lm

StrList.o:Strlist.h
main.o:Strlist.h

clean:
	rm -f *.a *.o StrList 