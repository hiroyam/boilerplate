all: main

main:
	$(CXX) main.cpp \
		-std=c++11 -Wall -O3 \
		-mavx -fopenmp

run:
	@echo "\033[33m=================================================\033[39m"
	./a.out

#   for assembler
# 	g++ main.cpp \
		-S -g -masm=intel \
		-std=c++11 -Wall -O3 \
		-mavx \
		-fopenmp
#	./a.out
