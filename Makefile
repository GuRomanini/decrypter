TAD.o: TAD.c
	gcc -o TAD.o -c TAD.c

crypt.o: crypt.c
	gcc -o crypt.o -c crypt.c

decrypt.o: decrypt.c
	gcc -o decrypt.o -c decrypt.c

main.o: main.c
	gcc -o main.o -c main.c

decrypter: TAD.o crypt.o decrypt.o main.o
	gcc -o decrypter TAD.o crypt.o decrypt.o main.o

all: decrypter

run: decrypter
	./decrypter

clean:
	rm TAD.o crypt.o decrypt.o main.o decrypter

zip: TAD.c TAD.h crypt.c crypt.h decrypt.c decrypt.h main.c Makefile
	zip decrypter.zip Makefile *.c *.h
