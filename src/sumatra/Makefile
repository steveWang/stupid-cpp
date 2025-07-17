CC := clang++
CCFLAGS := -O2 -std=c++20 -fprebuilt-module-path=. -Dvar=auto

all: main

clean:
	rm -f *.pcm *.o main

%.pcm: %.cppm
	${CC} ${CCFLAGS} --precompile $<

sumatra.pcm: Object.pcm String.pcm Boolean.pcm

Object.pcm: base.pcm
Boolean.pcm: Object.pcm
String.pcm: Object.pcm
System.out.println.pcm: sumatra.pcm

main: main.cc sumatra.pcm System.out.println.pcm Boolean.pcm
	${CC} ${CCFLAGS} main.cc *.pcm -o main
