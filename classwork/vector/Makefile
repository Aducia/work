all: main.out 	
vector.o: vector.cpp
	g++ -c vector.cpp -o  vector.o  
main.o: main.cpp
	g++ -c main.cpp -o main.o 
main.out: vector.o main.o	
	g++ vector.o main.o -o main.out 
