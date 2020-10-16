test: src/*.c src/components/*c
	cc -ftest-coverage -fprofile-arcs -o bin/test src/*.c src/components/*c -lcunit
