CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lpthread -lcheck
SOURCES = objreader/*.c matrix/*.c
TESTS = unit_tests.c
APPNAME = 3dviewer10.app

ifeq ($(shell uname -s), Linux)
	LFLAGS = -lm -lpthread -lcheck -lsubunit
	APPNAME = 3dviewer10
endif


all: clean uninstall install gcov_report dvi

install:
	@if [ ! -d build ] ; then mkdir build; fi
	cd build && qmake ../ && make

uninstall:
	rm -rf build

clean:
	rm -rf dist.tar
	rm -rf build
	rm -rf Documentation
	rm -rf report
	rm -rf *.a *.gcda *.gcno test test.info
	rm -rf *.o gcov_report *.dSYM

dvi:
	rm -rf Documentation	
	doxygen
	open Documentation/html/index.html
	

dist:
	rm -rf dist.tar
	tar -cvzf dist.tar build/$(APPNAME)
	

test: 
	$(CC) $(CFLAGS) $(SOURCES) $(TESTS) -o test -g -lm $(LFLAGS)
	@./test
	

gcov_report: clean add_coverage test
	./test
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	open report/index.html
	

add_coverage:
	$(eval CFLAGS += --coverage)

3dviewer10.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rc 3dviewer10.a *.o
	ranlib 3dviewer10.a
	rm -rf *.o
