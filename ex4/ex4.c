// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    char *null_array[] = {NULL};
    if(!fork())
    {
        execl("/bin/ls", NULL);
        printf("\n");
    }
    wait(NULL);
    if(!fork())
    {
        execle("/bin/ls", NULL, null_array);
        printf("\n");
    }
    wait(NULL);
    if(!fork())
    {
        execv("/bin/ls", null_array);
        printf("\n");
    }
    wait(NULL);
    return 0;
}

// The options denoting argument format provide ease of use for different use
// cases. Developers may find it easier to use the l (list) versions of exec
// when manually writing out the exec calls. Being able to supply the arguments
// as a vector (v) makes it easier to write a program that executes many
// different programs with different arguments based on input.
// The path (p) and environment (e) forms, similarly, allow the simulation of
// any kind of execution environment.
