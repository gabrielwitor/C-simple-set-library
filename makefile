all: c-simple-set

c-simple-set: main.o sets.o
	gcc -Wall -o main build/main.o build/sets.o

main.o: main.c
	gcc -c -Wall main.c
	mkdir -p build
	mv main.o build

sets.o: sets.c 
	gcc -c -Wall sets.c
	mkdir -p build
	mv sets.o build

clean:
	rm build/*.o
	rm main