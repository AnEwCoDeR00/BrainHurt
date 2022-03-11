# BrainHurt programming language

A small Interpreter Language based on brainf*ck
Contains a 3000 x 4 bytes of a array of integers in which you can store values and print them
BrainHurt is similar to brainf*ck in syntax and commands

# Files
main.c - The main compiler
compile.h - Compiles the text
file.h - For file i/o

# Commands
'.' - Print value of current pointer
'>' - increase the pointer value by 1
'<' - decrease the pointer value by 1
'+' - increase value of current position by next value 
'-' - increase value of current position by next value
'*' - Print value of current pointer in ascii value
'_' - Input a int and store the value in the current position
'"' - For single line comment ends if detects another quote
throws error if unexepected character is present or if Unxepected value to increase or decrease is given or too much incrementation or decrementation is done
default value of main array is 3000 you can increase it....
It may not work properly for comments and newlines

# Compiling Guide
For compilation you must have gcc installed
Use this command for making the compiler - 'gcc -o main main.c'
Then you will have main.exe in your folder
run this command to run any file of brainhurt - '.\main YourFile.hurt'

NOTE - This is just for testing my C programming skills.
