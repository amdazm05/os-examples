#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
  const char * pName = "./pipe1";
  int fd = open(pName,O_RDONLY);
  int num;
  while(read(fd,&num,sizeof(int))>0)
	  printf("%x \n",num);
  close(fd);
  unlink(pName);
  return 0;
}
