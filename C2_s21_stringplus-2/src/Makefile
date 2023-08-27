CC=gcc
CFLAGS=-c -Wall -Wextra -Werror -std=c11
LDFLAGS=-O2 -Wall -Wextra -Werror -std=c11
ADD_LIB=-lm -lrt -lpthread -lsubunit
SOURCE=$(wildcard s21_*.c)
OBJECTS=$(patsubst %.c,%.o, ${SOURCE}) # заменяет в именах всех исходников расширение
UNAME:=$(shell uname -s) # определяем ОС
ifeq ($(UNAME),Linux ) # Linux
	OPEN_CMD=xdg-open # команда для открытия отчета
	ADD_LIB=-lm -lrt -lpthread -lsubunit # дополнительные библиотеки
	BREW=/home/darkwolf/homebrew
endif
ifeq ($(UNAME),Darwin ) # MacOS
	OPEN_CMD=open
	ADD_LIB=
	BREW:=${HOME}/homebrew
endif
PATH := $(PATH):$(BREW)/bin # пути поиска lcov и genhtml
GCOV=--coverage
PROJECTNAME=s21_string
PROJECTNAMEOBJECT=s21_string.o
TESTC=check_string.c

all: clean ${PROJECTNAME}.a test

$(PROJECTNAME).a: ${SOURCE}
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a ${OBJECTS}
	ranlib $(PROJECTNAME).a

test: $(TESTC) ${PROJECTNAME}.a
	${CC} ${LDFLAGS} -o $@ $^ -lcheck ${ADD_LIB}
	./$@


gcov_report: clean ${SOURCE} $(TESTC)
	-mk_dir report
	${CC} $(CFLAGS) ${GCOV} ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a ${OBJECTS}
	ranlib $(PROJECTNAME).a
	${CC} ${LDFLAGS} -o $@ ${GCOV} $(TESTC) ${PROJECTNAME}.a -lcheck ${ADD_LIB}
	-./$@
	--gcov $(TESTC)
	if [ "$(UNAME)","Linux " ]; then \
        lcov -t ${PROJECTNAME} -o ${PROJECTNAME}.info -c -d .;\
		genhtml -o report ${PROJECTNAME}.info;\
    else \
        $(shell PATH=$(PATH) which lcov)  -t ${PROJECTNAME} -o ${PROJECTNAME}.info -c -d .;\
		$(shell PATH=$(PATH) which genhtml) -o report ${PROJECTNAME}.info;\
    fi
	-$(OPEN_CMD) ./report/index.html

rebuild: clean all

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/

.PHONY: all clean
