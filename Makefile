all: main.c
	gcc -o signals main.c

run: all
	./signals
