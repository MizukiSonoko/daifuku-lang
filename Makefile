
CC=clang++
TARGET=cook
OPTION=-std=c++0x -Wall

all: Token.o Lexer.o Perser.o Perser_core.o test.o
		$(CC) -O2 -o $(TARGET) $(OPTION) Token.o Lexer.o Perser.o Perser_core.o test.o

Token.o: Token.cpp
		$(CC) $(OPTION) -c Token.cpp

Lexer.o: Lexer.cpp
		$(CC) $(OPTION) -c Lexer.cpp

Perser.o: Perser.cpp
		$(CC) $(OPTION) -c Perser.cpp

Perser_core.o: Perser_core.cpp
		$(CC) $(OPTION) -c Perser_core.cpp

test.o: test.cpp
		$(CC) $(OPTION) -c test.cpp

clean:
		rm -f Token.o Lexer.o Perser.o Test.o Perser_core.o test.o
