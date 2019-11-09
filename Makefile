all: randfile.o main.o
	gcc -o randfile.out randfile.o main.o

randfile.o: randfile.c randfile.h
	gcc -c randfile.c

main.o: main.c randfile.h
	gcc -c main.c

clean:
	rm -f *.o *.out randfile
run:
	./randfile.out
