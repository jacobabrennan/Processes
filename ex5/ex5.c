// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Initialize buffer and pipe
    char reception_buffer[MSGSIZE];
    int com_pipe[2];
    // Open pipe
    int pipe_result = pipe(com_pipe);
    // Handle errors opening pipe
    if(pipe_result < 0)
    {
        fprintf(stderr, "Failed to open pipe.\n");
        exit(1);
    }
    // Start child (writing) process
    if(!fork())
    {
        write(com_pipe[1], msg1, MSGSIZE);
        write(com_pipe[1], msg2, MSGSIZE);
        write(com_pipe[1], msg3, MSGSIZE);
        return 0;
    }
    // Read data (parent process)
    for(int message_index=0; message_index<3; message_index++)
    {
        read(com_pipe[0], reception_buffer, MSGSIZE);
        printf("Message Received: %s\n", reception_buffer);
    }
    // End process
    return 0;
}
