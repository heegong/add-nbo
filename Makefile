all: add-nbo

add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o

add-nbo.o: add-nbo.cpp

clean:
	rm -f *.o 
	rm -f add-nbo



