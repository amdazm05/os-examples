#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

//Is a pipe example

#define Readend  0
#define Writeend 1

void report_die(const char * msg)
{
  perror(msg);
  exit(-1);
}

int main()
{
  int pipe_fd[2];
  char buf;
  const char * msg = "Sending over something";

  if(pipe(pipe_fd)<0) 
    report_die("pipe(...)");

  pid_t cpid = fork();

  if(cpid<0)
    report_die("fork(...)");
  
  //This is the parent process
  if(cpid==0)
  {
    close(pipe_fd[Writeend]);
    while(read(pipe_fd[Readend], &buf,1)>0)
    {
    	write(STDOUT_FILENO,&buf,sizeof(buf));
    }
    close(pipe_fd[Readend]);
    _exit(0);
  }

  //This is the child process
  else
  {
    close(pipe_fd[Readend]);
    write(pipe_fd[Writeend],msg,strlen(msg));
    close(pipe_fd[Writeend]);
    wait(0);
    exit(0);
  }

  //exit vs _exit is different , _exit is a signal to OS to exit and kill
  //exit is in C library its for terminating the program.
}

