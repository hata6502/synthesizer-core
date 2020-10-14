test: src/*.c src/components/*c
	cc -o bin/test src/*.c src/components/*c -lcunit
