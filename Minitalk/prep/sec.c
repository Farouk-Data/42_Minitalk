#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

//function to handle a signal when it's sent to the process
// void handler(int num)
// {
//     write(STDOUT_FILENO,"Not this time \n",15);
//     //signal(SIGINT,SIG_DFL);  //Reregister signal handler for default
// }

void handler(int signum)
{
    write(STDOUT_FILENO,"Error!",6);
}

void handle_segfault(int num)
{
    write(STDOUT_FILENO,"Segfault!\n",10);
}

int main(int argc,char **argv)
{
    // struct sigaction sa;
    // sa.sa_handler = handler;
    //the process won't be interrupted or terminated 
    //can't handle SIGKILL
    //int *p = NULL;

    //should segfault
    // signal(SIGSEGV,handle_segfault);
    // sigaction(SIGINT,&sa,NULL);
    // sigaction(SIGTERM,&sa,NULL);


    //*p = 45;

    //in the handler pos , we can pass SIG_IGN or SEF_DFL
    //signal(SIGINT, SIG_IGN);
    //signal(SIGINT, handler);
    // signal(SIGTERM,handler);
    struct sigaction action;

    action.sa_handler = handler;
    sigaction(SIGINT,&action,NULL); 
    
    while(1)
    {
        printf("Your PID : %d \n",getpid());
        sleep(1);
    }
    return 0;
}