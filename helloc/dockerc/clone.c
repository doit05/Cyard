#include "dockerc.h"

#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];
char * const child_args[] = {
        "/bin/bash",
        "NULL"
};

int child_main(void * args){
    printf("in child proces %d \n", getpid());
    execv(child_args[0], child_args);
    return 1;

}

int main(){
    printf("start %d \n", getpid());
    int child_pid = clone(child_main,child_stack + STACK_SIZE, SIGCHLD, NULL);
    int *ret = 0;
    int wait = waitpid(child_pid, ret, 0);
    printf("已经退出 wait : %d, ret : %d\n", wait, ret);
    return 0;

}