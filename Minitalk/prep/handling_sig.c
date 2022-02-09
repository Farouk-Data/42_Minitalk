#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void handler(int sigtype)
{
    write(1,"Ctrl+C not working! \n",21);
}

int main()
{
    //handling CTRL+C
    signal(SIGINT,handler);
    signal(SIGTERM, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    while (1)
    {
        printf("testing! \n");
        sleep(1);
    }
}