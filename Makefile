
test: test.cpp
	g++ -g -o test test.cpp

optparser: optparser.cpp
	g++ -std=c++0x -o optparser optparser.cpp -L/opt/view/lib -lsymtabAPI -I/opt/view/include -lparseAPI -linstructionAPI -lsymLite -ldynDwarf -ldynElf -lcommon -lelf

simpleopt: simpleopt.cc includes/cxxopts.hpp test
	g++ -std=c++0x -o simpleopt simpleopt.cc -L/opt/view/lib -lsymtabAPI -I/opt/view/include -lparseAPI -linstructionAPI -lsymLite -ldynDwarf -ldynElf -lcommon -lelf

test2.json: optparser test
	./optparser test && rm test.dot && mv test.json test2.json

test.json: simpleopt test
	./simpleopt -b test

clean:
	rm -rf test cfg dissassemble simpleopt