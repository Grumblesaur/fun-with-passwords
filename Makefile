all: crypt crack

crypt: our_crypt.o
	g++ our_crypt.o -o crypt -lcrypt

crypt.o:
	g++ -c our_crypt.cpp -lcrypt

crack: crack.o
	g++ crack.o -o crack -lcrypt

crack.o: crack.cpp
	g++ -c crack.cpp -lcrypt

clean:
	rm -f *.o crack crypt
