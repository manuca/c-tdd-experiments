CFLAGS=-Wall -std=c99

.PHONY: run_tests

run_tests: tests
	./tests

tests: tests.c vault.c vault.h
	gcc -Wall -std=c99 vault.c tests.c -o tests


cli_demo: cli_demo.o vault.o
	gcc -Wall -std=c99 cli_demo.o vault.o -lncurses -o cli_demo
