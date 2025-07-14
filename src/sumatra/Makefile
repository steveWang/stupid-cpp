CC := clang++
CCFLAGS := -O2 -std=c++20 -fprebuilt-module-path=. -Dvar=auto

all: main

clean:
	rm -f *.pcm *.o main

Object.pcm: Object.cppm
	${CC} ${CCFLAGS} --precompile Object.cppm

String.pcm: String.cppm Object.pcm
	${CC} ${CCFLAGS} --precompile String.cppm

sumatra.pcm: sumatra.cppm Object.pcm String.pcm
	${CC} ${CCFLAGS} --precompile sumatra.cppm

System.out.println.pcm: sumatra.pcm System.out.println.cppm
	${CC} ${CCFLAGS} --precompile System.out.println.cppm

main: main.cc sumatra.pcm System.out.println.pcm
	${CC} ${CCFLAGS} main.cc *.pcm -o main
