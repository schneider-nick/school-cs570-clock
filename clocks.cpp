/*
*Name: Nick Scneider, Brian Dobransky
*Username: cssc1093, cssc1094
*Class: CS570, Summer 2017
*Assignment: Assignment #3, clocks
*Due: 6-26-2017
*Instructor: Prof. Leonard
*File: clocks
*/
extern "C"{
#include <unistd.h>//sleep and getpid
#include <stdlib.h>//need for exit
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include "clocks.h"
}
#include <iostream>//need to use cin and cout
#include <string>//need for string
#include <ctime>//need for time


using namespace std;
volatile sig_atomic_t end = 1;
pid_t child1, child2, parent;

void signal_child(int handle){
	end =0;
	}

//prints the quote to file while the semaphore is down.
void print_time(int hours, int minutes, int seconds){
	time_t now;
	struct tm * current_time;
	while(end){
		now = time(0);
		current_time = localtime(&now);
		cout<<"The current time is: "<< current_time->tm_hour<<":"<<current_time->tm_min<<":"<<current_time->tm_sec<<endl;
		if(current_time->tm_sec == seconds){
			if(current_time->tm_min = minutes && current_time->tm_hour == hours)
				cout<<"Alarm!!  Your time is up!"<<endl;
			}
		sleep(1);
		}
	}


void run_timer(int seconds_to_run){
	sleep(seconds_to_run);
	kill(child1, SIGALRM);
	exit(0);
	}

 
void clocks::run(int seconds_to_run, int hours, int minutes, int seconds){
	if((child1=fork()) < 0){
		perror("fork failed");
		exit(1);
		}
	if(child1 == 0){
		if((child2=fork()) < 0){
			perror("fork failed");
			exit(1);
			}
		if(child2 == 0){
			run_timer(seconds_to_run);
		}else{
			signal(SIGALRM, signal_child);
			print_time(hours, minutes, seconds);
			}
	}else {
		for(;;){
			pid_t pid_child;
			pid_child = wait(NULL);
			if(pid_child == child1)
				break;
			}
		return ;
		}

}


//constructor.
clocks::clocks(){
//construtor
}


