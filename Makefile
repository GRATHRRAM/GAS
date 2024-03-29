COMPILER=cc
FLAGS=-O3 -Wall -Wextra -g

grah16.out: libconv.a libgrah16.a
	$(COMPILER) $(FLAGS) main.c  -L. -I. -lgrah16 -lconv -o grah16.out

conv.o: conv.c
	$(COMPILER) $(FLAGS) -c conv.c -o conv.o

grah16.o: grah16.c
	$(COMPILER) $(FLAGS) -c grah16.c -o grah16.o

libconv.a: conv.o 
	ar ruv libconv.a conv.o

libgrah16.a: grah16.o 
	ar ruv libgrah16.a grah16.o

clean: 
	rm *.a *.o
