#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int pid = fork();

    if (pid < 0)
    {
        return (0);
    }
    if (pid == 0)
    {
        while (1)
        {
            printf("Testing signals \n");
            usleep(50000);
        }
    }
    else
    {
        sleep(2);
        kill(pid, SIGKILL);
        wait(NULL);
    }
    return (0);
}