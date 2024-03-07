CPPFLAGS=-g
CC=g++

towers: towers.cpp
	g++ -o towers towers.cpp Stack.cpp

clean:
	rm -rf towers

install:
	cp towers /usr/local/bin/towers