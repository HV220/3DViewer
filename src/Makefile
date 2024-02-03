GCC = g++ -std=c++17 -g -Wall -Werror -Wextra
TEST = tests/*_test.cc
MODEL = app/models/sources/*_model.cc
GCOV =--coverage
LIBA = *.a
LIBO = *.o
OS = $(shell uname)
FILECASE_H = `find . -name "*.h"`
FILECASE_CC = `find . -name "*.cc"`

ifeq ($(OS), Darwin)
LIBFLAGS = -lm -lgtest -lstdc++ -lgtest_main
else
LIBFLAGS=-lstdc++ `pkg-config --cflags --libs gtest  --libs gtest_main`
endif

all: clean tests

tests: clean
	$(GCC) $(TEST) $(MODEL) app/controllers/sources/*.cc $(LIBFLAGS)  -o test
	./test

clean:
	rm -rf *.o *.a  *.out test *.dSYM  report coverage.info *.gcda *.gcno *.txt *.tgz .clang-format *.user


dvi:
	open ./readme.html

dist:
	rm -rf Archive_3dviewer_v2.0/
	mkdir Archive_3dviewer_v2.0/
	mkdir Archive_3dviewer_v2.0/src
	cp -rf Makefile app Archive_3dviewer_v2.0/src/
	tar cvzf Archive_3dviewer_v2.0.tgz Archive_3dviewer_v2.0/
	rm -rf Archive_3dviewer_v2.0/

s21_3dviewer.a: clean
	$(GCC) -c $(MODEL) $(TEST) app/controllers/sources/*.cc
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

gcov_report: s21_3dviewer.a
	$(GCC) $(GCOV) $(MODEL) app/controllers/sources/*.cc $(LIBA) -L. $(LIBA)  $(LIBFLAGS) -o test
	./test
	lcov -t "test" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

install:
	make clean
	mkdir build
	cd build && qmake ../app/3dviewer.pro && make

uninstall: 
	rm -rf build*

check:
	cp ../materials/linters/.clang-format ./
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(FILECASE_H) $(FILECASE_CC)
	clang-format -style=Google -n $(FILECASE_H) $(FILECASE_CC)
	clang-format -style=Google -i $(FILECASE_H) $(FILECASE_CC)

ifeq ($(OS), Darwin)
	leaks --atExit -- test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif

open_app:
ifeq ($(OS), Darwin)
	./build/3dviewer.app/Contents/MacOS/3dviewer
else
	./build/3dviewer
endif