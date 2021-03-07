OBJECTS=main.o List.o Node.o Dnode.o DList.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o Dnode.o DList.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o List.o Node.o List.o Dnode.o DList.o
	g++ -o tests tests.o List.o Node.o Dnode.o DList.o

main.o: main.cpp List.h DList.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

DList: DList.cpp DList.h DNode.h

Dnode.o: Dnode.cpp Dnode.h

tests.o: tests.cpp doctest.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f $(OBJECTS) tests.o
