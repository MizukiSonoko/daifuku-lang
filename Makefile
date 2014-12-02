
CC=clang++
TARGET=cook

all: Token.o Lexer.o Perser.o test.o
		$(CC) -Wall -O2 -o $(TARGET) Token.o Lexer.o Perser.o test.o

Token.o: Token.cpp
		$(CC) -Wall -c Token.cpp

Lexer.o: Lexer.cpp
		$(CC) -Wall -c Lexer.cpp

Perser.o: Perser.cpp
		$(CC) -Wall -c Perser.cpp

test.o: test.cpp
		$(CC) -Wall -c test.cpp

clean:
		rm -f token.o lexer.o perser.o test.o
