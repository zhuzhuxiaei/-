#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    pid_t child_pid;
    child_pid=fork();
    	if(child_pid==0){
      	 	char* arg_list[]={
        		"echo","i am the son",
    	};
		execv("/bin/echo",arg_list);
       exit(0);
    }
    	else if(child_pid>0)
	{
       waitpid(-1,NULL,0);
		printf("子进程标志符: %d\n",child_pid);
    }
	else{
		printf("error\n");
	}
    exit(0);
}
