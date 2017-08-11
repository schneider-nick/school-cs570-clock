#Name: Nick Schneider, Brian Dobransky
#Username: cssc1093, cssc1094
#Class: CS570, Summer 2017
#Assignment: assignment #3, clocks
#Due: 6-26-2017
#Instructor: Prof. Leonard
#Files: Makefile
aclock: clocks.o main.o
	g++  clocks.o main.o -o aclock

main.o: main.cpp clocks.h
	g++ -c main.cpp

clocks.o: clocks.cpp clocks.h
	g++  -c clocks.cpp

clean:
	rm -f *.o aclock quote.txt

tar:
	tar -czvf clocks.tar.gz main.cpp clocks.h clocks.cpp Makefile README.txt
