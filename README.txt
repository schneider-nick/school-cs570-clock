/*
*Name: Nick Schneider, Brian Dobransky
*Username: cssc1093, cssc1094
*Class: CS570, Summer 2017
*Assignment: Assignment #3, clock
*Due: 6-26-2017
*Instructor: Prof. Leonard
*File: README.txt
*/


usage: ./aclock


files:
clocks.cpp
clocks.h
main.cpp
makefile
README.txt

compile instructions:
"make" : this will compile all source and create executable "aclock"

operating instructions:
./aclock

significant design decisions:

    Design and implement an interruptible, clock and timer.
        You shall create a program that does the following:
        - Upon startup, read the total runtime (in seconds) the user wants the program to run for.  A
        default value of 30 seconds will be used if the user does not include the time when launching
        the program, i.e., [username@edoras ~/a3]$ aclock 23 causes the program to run for 23
        seconds, [username@edoras ~/a3]$ aclock (no arguments), the program would run for 30
        seconds, and [username@edoras ~/a3]$ aclock 128 the program would run for 2 minutes
        and 8 seconds.
        - The program (the main process and thread) shall create two child processes/threads (your
        choice), then busy-waits until all child processes/threads are complete and then perform a
        clean exit.
        - The first child process shall implement a clock which prints the hour, minute, and second
        once every second (in human readable form using localtime).  If the hour, minute, and
        second matches the user-provided alarm time, the Alarm would be printed as well.
        - The second child process/thread, upon reaching the specified number of seconds
        (countdown timer perhaps?), will notify (using signal(), or pipe()) the other child
        process/threads (i.e. it's sibling process/threads) telling them to terminate and then
        terminate itself.
        - Once all child processes/threads have terminated, the parent shall print a friendly message, 
        then perform a clean exit.

known bugs:
no known bugs

lessons learned:

            In this assignment the lessons we learned were the important usage of threads to keep track 
        of processes in time that is human readable.  The concept of processes/threads in this assignment 
        allow the user to set the alarm for a set number of seconds required by the user or by default 
        to run only for 30 seconds.  these processes are being handled by the child process to complete
        the task assigned to it by the parent.  
