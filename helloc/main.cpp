#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

#define STACK_SIZE = (1024 * 1024);

static char child_stack[STACK_SIZE];
char * const child_args[] = {
        "/bin/bash",
        "NULL"
};

int child_main(void * args){
    printf("in child proces\n");
    execv(child_args[0], child_args);
    return 1;

}

int main(){
    printf("start \n");
    int in_child_process = clone(child_main,child_stack + STACK_SIZE, SIGCHLD, NULL);
    waitpid(in_child_process, NULL, 0);
    printf("已经退出\n");
    return 0;

}