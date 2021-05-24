exec = cook.out 
sources = ${wildcard src/runtime/*.cpp src/runtime/*/*.cpp }
headers = ${wildcard src/runtime/*.hpp src/runtime/*/*.hpp}
objects = ${sources:.cpp=.o}
flags = -g -Wall -Wextra -std=c++20 

all: cookie 

cookie: ${sources} ${headers}
	g++ ${sources} -o cookie ${flags} -lm -ldl -rdynamic 

clean:
	-rm *.out 
	-rm src/runtime/*.o
	-rm src/runtime/compile/*.o
	-rm *.a 
	-rm cookie 

lint:
	clang-tidy src/runtime/compile/*.cpp src/runtime/compile/*.hpp

format:
	clang-format -i -style=llvm src/runtime/*.cpp src/runtime/compile/*.cpp src/runtime/compile/*.hpp 
