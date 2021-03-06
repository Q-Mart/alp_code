#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  int zero = 0;
  const int megabyte = 1024 * 1024;

  char* filename = argv[1];
  size_t length = (size_t) atoi (argv[2]) * megabyte;

  int fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0666);
  //Jump to 1 byte short of the where we want the file to end
  lseek(fd, length - 1, SEEK_SET);
  //Write a 0 byte
  write(fd, &zero, 1);
  
  close(fd);

  return 0;
}
