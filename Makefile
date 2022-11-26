all:
	gcc puzzle.c puzzsup.c -o build/main

run:
	./build/main