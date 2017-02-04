#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  //The path of the new file
  char* path = argv[1];
  //The file permissions
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

  //Create the file
  int fd = open(path, O_WRONLY | O_EXCL | O_CREAT, mode);
  if (fd == -1)
  {
    //An error has occured
    perror("open");
    return 1;
  }

  return 0;
}
