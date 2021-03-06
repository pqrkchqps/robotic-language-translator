CXX_DIR = ../lib/cxxtest
CXXTEST = $(CXX_DIR)/cxxtestgen.pl
CXXFLAGS = --error-printer --abort-on-fail --have-eh

FLAGS = -Wall -g 

# Program files.
readInput.o:	readInput.cpp readInput.h
	g++ $(FLAGS) -std=c++0x -c readInput.cpp 

regex.o:	regex.cpp regex.h
	g++ $(FLAGS) -c regex.cpp 

scanner.o:	scanner.cpp scanner.h regex.o
	g++ $(FLAGS) -std=c++0x -c scanner.cpp regex.o

parser.o:	parser.cpp parser.h parseResult.o extToken.o
	g++ $(FLAGS) -std=c++0x -c parser.cpp parseResult.o extToken.o

extToken.o:	extToken.cpp extToken.h
	g++ $(FLAGS) -c extToken.cpp

parseResult.o:	parseResult.cpp parseResult.h 
	g++ $(FLAGS) -std=c++0x -c parseResult.cpp

cffc.o:		cffc.cpp parser.h readInput.h
	g++ $(FLAGS) -c cffc.cpp

cffc:	cffc.o extToken.o parseResult.o parser.o scanner.o regex.o readInput.o
	g++ $(FLAGS) cffc.cpp extToken.o parseResult.o parser.o scanner.o regex.o readInput.o -o cffc

# Testing files and targets.
run-tests:	regex_tests scanner_tests parser_tests ast_tests
	./regex_tests
	./scanner_tests
	./parser_tests
	./ast_tests

codeGen_tests:	codeGen_tests.cpp readInput.o scanner.o extToken.o parser.o parseResult.o regex.o
	g++ $(FLAGS) -I$(CXX_DIR) -o codeGen_tests codeGen_tests.cpp readInput.o scanner.o extToken.o parser.o parseResult.o regex.o

codeGen_tests.cpp:	codeGen_tests.h 
	$(CXXTEST) $(CXXFLAGS) -o codeGen_tests.cpp codeGen_tests.h

regex_tests:	regex_tests.cpp regex.o
	g++ $(FLAGS) -I$(CXX_DIR) -o regex_tests regex.o regex_tests.cpp

regex_tests.cpp:	regex.h regex_tests.h
	$(CXXTEST) $(CXXFLAGS) -o regex_tests.cpp regex_tests.h

scanner_tests:	scanner_tests.cpp scanner.o regex.o readInput.o
	g++ $(FLAGS) -I$(CXX_DIR)  -o scanner_tests \
		scanner.o regex.o readInput.o scanner_tests.cpp

scanner_tests.cpp:	scanner.o scanner_tests.h readInput.h
	$(CXXTEST) $(CXXFLAGS) -o scanner_tests.cpp scanner_tests.h

parser_tests:	parser_tests.cpp parser.o readInput.o scanner.o extToken.o parseResult.o
	g++ $(FLAGS) -I$(CXX_DIR) -o parser_tests parser.o extToken.o regex.o scanner.o parseResult.o readInput.o parser_tests.cpp

parser_tests.cpp:	parser.o parser_tests.h readInput.h
	$(CXXTEST) $(CXXFLAGS) -o parser_tests.cpp parser_tests.h

ast_tests:	ast_tests.cpp parser.o readInput.o scanner.o extToken.o parseResult.o regex.o
	g++ $(FLAGS) -I$(CXX_DIR) -o ast_tests parser.o extToken.o regex.o scanner.o parseResult.o readInput.o ast_tests.cpp

ast_tests.cpp:	parser.h ast_tests.h parseResult.h
	$(CXXTEST) $(CXXFLAGS) -o ast_tests.cpp ast_tests.h scanner.h parseResult.h

clean:
	rm -Rf *.o \
		regex_tests regex_tests.cpp \
		scanner_tests scanner_tests.cpp \
		parser_tests parser_tests.cpp \
		ast_tests ast_tests.cpp \
		cffc \

