CC := gcc

sudom: main.o sudom.o
	$(CC) -o sudom main.o sudom.o

main.o: main.c
	$(CC) -c main.c

sudom.o: sudom.c sudom.h
	$(CC) -c sudom.c

clean: 
	rm sudom main.o sudom.o

