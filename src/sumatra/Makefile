CC := clang++
CCFLAGS := -O2

all: main

clean:
	rm -f *.pcm *.o main

String.pcm: String.cppm
	${CC} ${CCFLAGS} --precompile String.cppm -std=c++20

System.out.println.pcm: System.out.println.cppm String.pcm
	${CC} ${CCFLAGS} --precompile System.out.println.cppm -std=c++20 -fmodule-file=String=String.pcm

main: main.cc String.pcm System.out.println.pcm
	${CC} ${CCFLAGS} main.cc --std=c++20 -fprebuilt-module-path=. *.pcm -o main
