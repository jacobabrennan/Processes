// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *text_txt = fopen("text.txt", "w");
    int pid = fork();

    if(!pid)
    {
        fprintf(text_txt, "Child\n");
    }
    else
    {
        fprintf(text_txt, "Parent\n");
    }
    return 0;
}

// Both the processes were able to write to the file without any issues.
// The order they wrote in was effectively random.
// Further, each was able to use the write mode without first deleting the file.