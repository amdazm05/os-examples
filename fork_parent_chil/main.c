#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid = fork();
	if(-1==pid)
	{
	  printf("Error");
	}
	else if(0==pid)
	{
	  printf("Child node");
	}
	else
	{
	  printf("Parent code");
	}
	return 0;
}
