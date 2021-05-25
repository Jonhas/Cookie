
sources = ${wildcard src/runtime/*.cpp src/runtime/*/*.cpp }
headers = ${wildcard src/runtime/*.hpp src/runtime/*/*.hpp}
objects = ${sources:.cpp=.o}
flags = -g -Wall -Wextra -O2 -std=c++20 

all: cookie # io.so

cookie: ${sources} ${headers}
	g++ ${sources} -o cookie ${flags} -lm -ldl -rdynamic 


# io.so: ${wildcard src/modules/io/*.hpp src/modules/io/*.cpp}
# 	g++ ${wildcard src/modules/io/*.cpp} -shared -std=c++20  -o io.so -lcookie 

clean:
	-rm *.out 
	-rm src/runtime/*.o
	-rm src/runtime/compile/*.o
	-rm *.a 
	-rm *.so
	-rm cookie 

lint:
	clang-tidy -system-headers -header-filter=.* --extra-arg=-std=c++20 src/runtime/compile/*.cpp src/runtime/compile/*.hpp

format:
	clang-format -i -style=llvm ${sources} ${headers}
