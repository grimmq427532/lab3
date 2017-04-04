main: Clock.o main.o
	g++ -o main Clock.o main.o
	
Clock.o: Clock.h Clock.cpp
	g++ -c Clock.cpp
	
main.o: main.cpp Clock.h
	g++ -c main.cpp
	
clean:
	rm *.o