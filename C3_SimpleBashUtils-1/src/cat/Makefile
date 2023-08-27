CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: s21_cat

s21_cat: cat clean

cat: cat_main.o
	$(CC) array.o cat_main.o cat_parcer.o cat_print.o -o ./s21_cat

cat_main.o: array.o cat_parcer.o cat_print.o
	$(CC) $(CFLAGS) cat_main.c

array.o:
	$(CC) $(CFLAGS) ../common/array.c

cat_parcer.o:
	$(CC) $(CFLAGS) cat_parcer.c

cat_print.o:
	$(CC) $(CFLAGS) cat_print.c

clean:
	rm -rf *.o *.a

rebuild:
	rm -rf *.o *.a *.so ./s21_cat
	make all