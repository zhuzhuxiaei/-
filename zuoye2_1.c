#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    pid_t kid_pid;
    printf("父亲的pid: %d\n",(int)getpid());
    kid_pid=fork();
    if(kid_pid>0){
        while(1)
        printf("我是父进程 %d\n",(int)getpid());
    }
    else if(kid_pid==0)
    {
        while(1)
        printf("我是子进程 %d\n",(int)getpid());
    }
    return 0;
}
