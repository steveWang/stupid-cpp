CC := clang++
CCFLAGS := -O2 -std=c++20 -fprebuilt-module-path=.

all: main

clean:
	rm -f *.pcm *.o main

Object.pcm: Object.cppm
	${CC} ${CCFLAGS} --precompile Object.cppm

String.pcm: String.cppm Object.pcm
	${CC} ${CCFLAGS} --precompile String.cppm

System.out.println.pcm: System.out.println.cppm String.pcm
	${CC} ${CCFLAGS} --precompile System.out.println.cppm

main: main.cc String.pcm System.out.println.pcm
	${CC} ${CCFLAGS} main.cc *.pcm -o main
