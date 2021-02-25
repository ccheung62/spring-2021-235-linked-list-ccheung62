OBJECTS=main.o List.o Node.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o List.o Node.o
	g++ -o tests tests.o List.o Node.o

main.o: main.cpp List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

tests.o: tests.cpp doctest.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f $(OBJECTS) tests.o
