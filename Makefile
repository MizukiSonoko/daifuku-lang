
CC=clang++
TARGET=cook

LLVM_CONFIG = llvm-config
LLVM_FLAGS = --cxxflags --ldflags --libs

OPTION=-std=c++0x -Wall -I /usr/local/llvm/include/
OPTION_LLVM=-std=c++0x -Wall -lpthread -I /usr/local/llvm/include/ `$(LLVM_CONFIG) $(LLVM_FLAGS)` -ldl


TEST_AC_1=t_accept_1.recipe
TEST_AC_2=t_accept_2.recipe
TEST_AC_3=t_accept_3.recipe
TEST_WA_1=t_failed_1.recipe
TEST_WA_2=t_failed_2.recipe
TEST_WA_3=t_failed_3.recipe

all: Token.o Lexer.o Perser.o Perser_core.o Perser_speculate.o CodeGen.o test.o
		$(CC)  Token.o Lexer.o Perser.o Perser_core.o Perser_speculate.o CodeGen.o test.o $(OPTION_LLVM) -o $(TARGET)

Token.o: Token.cpp
		$(CC) $(OPTION) -c Token.cpp

Lexer.o: Lexer.cpp
		$(CC) $(OPTION) -c Lexer.cpp

Perser.o: Perser.cpp
		$(CC) $(OPTION) -c Perser.cpp

Perser_core.o: Perser_core.cpp
		$(CC) $(OPTION) -c Perser_core.cpp

Perser_speculate.o: Perser_speculate.cpp
		$(CC) $(OPTION) -c Perser_speculate.cpp

CodeGen.o: CodeGen.cpp
		$(CC) $(OPTION) -c CodeGen.cpp

test.o: test.cpp
		$(CC) $(OPTION_LLVM) -c test.cpp

debug:
		./$(TARGET) -d -i $(TEST_AC_1)

test:
		./$(TARGET) -i $(TEST_AC_1)
		./$(TARGET) -i $(TEST_AC_2)
		./$(TARGET) -i $(TEST_AC_3)
		./$(TARGET) -i $(TEST_WA_1)
		./$(TARGET) -i $(TEST_WA_2)
		./$(TARGET) -i $(TEST_WA_3)

clean:
		rm -f Token.o Lexer.o Perser.o Test.o Perser_core.o Perser_speculate.o test.o
