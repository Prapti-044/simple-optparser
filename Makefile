
test: test.cpp
	g++ -g -o test test.cpp

simpleopt: simpleopt.cc includes/cxxopts.hpp test
	g++ -std=c++0x -o simpleopt simpleopt.cc -L/opt/view/lib -lsymtabAPI -I/opt/view/include -lparseAPI -linstructionAPI -lsymLite -ldynDwarf -ldynElf -lcommon -lelf

test.json: simpleopt test
	./simpleopt -b test

clean:
	rm -rf test simpleopt test.json