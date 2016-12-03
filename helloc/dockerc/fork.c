#include "dockerc.h"

int main(){
    pid_t fpid;
    int count = 0;
    fpid = fork();
    if(fpid < 0){
        printf("fork err");
    } else if(fpid == 0){
        printf("i am child %d !\n", getpid());
    } else{
        printf("i am parent %d \n", getpid());
    }
    return 0;
}