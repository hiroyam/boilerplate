all: main

main:
	$(CXX) main.cpp \
		-std=c++1z -Wall -O3 \
		-mavx -fopenmp

run:
	./a.out

#   for assembler
# 	g++ main.cpp \
		-S -g -masm=intel \
		-std=c++11 -Wall -O3 \
		-mavx \
		-fopenmp
#	./a.out
