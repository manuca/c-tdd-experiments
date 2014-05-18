CFLAGS=-Wall -std=c99

.PHONY: run_tests

run_tests: tests
	./tests

tests: tests.c vault.c vault.h
	gcc -Wall -std=c99 vault.c tests.c -o tests
