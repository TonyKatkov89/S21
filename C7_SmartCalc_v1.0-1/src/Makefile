CC=gcc
CFLAGS=-c -g -Wall -Wextra -Werror -std=c11
LDFLAGS=-O0 -Wall -Wextra -Werror -std=c11
ADD_LIB=-lm -lrt -lpthread -lsubunit
ADD_LIB=-lm -lrt -lpthread -lsubunit
APP_FLDR=app/$(PROJECTNAME)/
TST_FLDR=check/
SOURCE=$(wildcard $(APP_FLDR)*.c)
OBJECTS=$(patsubst $(APP_FLDR)%.c,%.o, ${SOURCE}) 
TESTC=$(wildcard $(TST_FLDR)*_tests.c)
TSTOBJ=$(patsubst $(APP_FLDR)%.c,%.o, ${TESTC}) # changes extensions of all .c files ot .o
UNAME:=$(shell uname -s) # check OS
ifeq ($(UNAME),Linux ) # Linux
	OPEN_CMD=lynx # команда для открытия отчета
	ADD_LIB=-lm -lrt -lpthread -lsubunit # дополнительные библиотеки
	BREW=/home/darkwolf/homebrew
endif
ifeq ($(UNAME),Darwin ) # MacOS
	OPEN_CMD=open
	ADD_LIB=
	BREW:=${HOME}/homebrew
endif
PATH := $(PATH):$(BREW)/bin # paths to lcov and genhtml
GCOV=--coverage
PROJECTNAME=S21_SmartCalc

all: clean ${PROJECTNAME}.a test

install:
	@if [ ! -d ../build ] ; then mkdir ../build; fi
	qmake6 $(APP_FLDR)${PROJECTNAME}.pro -o $(APP_FLDR)${PROJECTNAME}_makefile
	cd $(APP_FLDR) && make install -f ${PROJECTNAME}_makefile
	rm -rf $(APP_FLDR)${PROJECTNAME}
	make clean

uninstall:
	cd $(APP_FLDR) && make uninstall -f ${PROJECTNAME}_makefile

dvi:
	@if [ ! -d ../dvi ] ; then mkdir ../dvi; fi
	doxygen dvi_config

dist:
	@if [ ! -d ../dist ] ; then mkdir ../dist; fi
	cd $(APP_FLDR) && make dist -f ${PROJECTNAME}_makefile
	mv $(APP_FLDR)*.tar* ../dist

$(PROJECTNAME).a:
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a ${OBJECTS}
	ranlib $(PROJECTNAME).a

unit_tests.o:
	${CC} $(CFLAGS) ${TESTC}

test: ${TSTOBJ} ${PROJECTNAME}.a
	${CC} ${LDFLAGS} -o $@ $^ -lcheck ${ADD_LIB}
	rm -rf *.o
	rm -rf *.a
	valgrind --tool=memcheck --leak-check=yes ./$@
	


gcov_report: clean ${SOURCE} $(TESTC)
	-mk_dir report
	${CC} $(CFLAGS) ${GCOV} ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a ${OBJECTS}
	ranlib $(PROJECTNAME).a
#	${CC} $(CFLAGS) ${TESTC}
	${CC} ${LDFLAGS} -o $@ ${GCOV} $(TESTC) ${PROJECTNAME}.a -lcheck ${ADD_LIB}
	./$@
	gcov $(TESTC)
	if [ "$(UNAME)","Linux " ]; then \
        lcov -t ${PROJECTNAME} -o ${PROJECTNAME}.info -c -d .;\
		genhtml -o report ${PROJECTNAME}.info;\
    else \
        $(shell PATH=$(PATH) which lcov)  -t ${PROJECTNAME} -o ${PROJECTNAME}.info -c -d .;\
		$(shell PATH=$(PATH) which genhtml) -o report ${PROJECTNAME}.info;\
    fi
	rm -rf *.o -rf *.gcno *.a *.gcda *.info *.gcov ./gcov_report
	$(OPEN_CMD) ./report/index.html

rebuild: clean all

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf ./dvi/
	-rm -rf ./app/${PROJECTNAME}/*.o
	-rm -rf ./app/${PROJECTNAME}/*.a
	-rm -rf ./app/${PROJECTNAME}/moc_*.cpp

.PHONY: all clean
