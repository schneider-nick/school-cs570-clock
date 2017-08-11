/*
*Name: Nick Scneider, Brian Dobransky
*Username: cssc1093, cssc1094
*Class: CS570, Summer 2017
*Assignment: Assignment #3, clock
*Due: 6-26-2017
*Instructor: Prof. Leonard
*File: main.cpp
*/

#include <iostream>
 
extern "C"{
	#include <stdlib.h>
	#include "clocks.h"
	}

using namespace std;

#define default_seconds 30

int main(int argc, char* argv[]){
	clocks clock;
	switch (argc) {
		case 1:
			clock.run(default_seconds, 0, 0, 0);
			break;
		case 2:
			clock.run(atoi(argv[1]), 0, 0, 0);
			break;	
		case 3:
			cout<<"Invald number of inputs. program closing."<<endl;
			break;

		case 4:
			cout<<"Invald number of inputs. program closing."<<endl;
			break;

		case 5:
			clock.run(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
			break;
	
		default:
			cout<<"Invald number of inputs. program closing."<<endl;
		}
	cout<<"end program"<<endl;
	return 0;
	}
