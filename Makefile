CC = gcc
CFLAG = -Wall
DEPS = graph.h queue.h
OBJ = main.o graph.o queue.o

%.o:%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAG)

main:$(OBJ)
	$(CC) $^ -o $@ $(CFLAG)

debug:main.c graph.c queue.c
	$(CC) -g $^

clean:
	rm *.o a.out

run:
	./main