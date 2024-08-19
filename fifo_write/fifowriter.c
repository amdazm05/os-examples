#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
  const char * pName = "./pipe1";
  mkfifo(pName,0777);
  int fd = open(pName, O_CREAT | O_WRONLY);
  int i;
  for(i =0;i<256;i++)
  {
    int n = i*2;
    write(fd,&n,sizeof(int));
  } 
  close(fd);
  unlink(pName);
  // command & means run in the background.
  return 0;
}
