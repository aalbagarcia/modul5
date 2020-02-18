all: bin doc

bin: main.o 
	gcc obj/main.o -o bin/is_armstrong_number -lm 
main.o : main.c
	gcc -c main.c -o obj/main.o

clean: clean-doc clean-obj clean-bin

clean-obj:
	rm -f obj/*
clean-bin:
	rm -f bin/*
clean-doc:
	rm -rf html latex
doc: clean-doc
	doxygen
cppcheck: 
	cppcheck --enable=all --inconclusive *.c 

cppcheck-xml: 
	cppcheck --enable=all --inconclusive --xml --xml-version=2 *.c 2> reports/cppcheck/report.xml
