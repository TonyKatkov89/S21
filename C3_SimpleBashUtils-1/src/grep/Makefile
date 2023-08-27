CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: s21_grep 

s21_grep: grep clean

grep: grep_main
	$(CC) grep_main.o grep_print.o grep_search.o array.o grep_parcer.o  -o ./s21_grep -lncurses

grep_main: array.o grep_parcer.o grep_search.o grep_print.o
	$(CC) $(CFLAGS) grep_main.c -lncurses

array.o:
	$(CC) $(CFLAGS) ../common/array.c

grep_parcer.o:
	$(CC) $(CFLAGS) grep_parcer.c -lncurses

grep_search.o:
	$(CC) $(CFLAGS) grep_search.c -lncurses

grep_print.o:
	$(CC) $(CFLAGS) grep_print.c -lncurses

clean:
	rm -rf *.o *.a

rebuild:
	rm -rf *.o *.a *.so ./s21_grep
	make all