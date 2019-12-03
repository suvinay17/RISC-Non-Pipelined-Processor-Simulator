DEBUG_FLAG= -DDBUG -g -Wall
CFLAGS=-DDBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ S(CFLAGS) -c $<

Main: 
