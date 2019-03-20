// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int pid = fork();
    if(!pid){
        printf("Child X: %d\n", x);
        x = 200;
        exit(0);
    } else {
        printf("Parent X: %d\n", x);
        x = 300;
    }
    return 0;
}

// Both printf statements output a value of 100 for x,
// reflecting how each process gets its own distinct copy of x.
