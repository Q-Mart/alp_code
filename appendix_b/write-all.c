#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

//Write all of COUNT bytes from BUFFER to the file descriptor
//Returns either -1 or the number of bytes written
ssize_t write_all(int fd, const void* buffer, size_t count)
{
  size_t left_to_write = count;
  while (left_to_write > 0) {
    size_t written = write(fd, buffer, count);
    if (written == -1)
      return -1;
    else
      left_to_write -= written;
  }
  
  assert(left_to_write == 0);
  return count;
}

int main(int argc, char* argv[])
{
  int fd = open(argv[1], O_CREAT | O_APPEND | O_WRONLY, 0666);
  char string[] = "The quick brown fox jumped over the lazy dog";

  write_all(fd, string, sizeof(string));

  close(fd);
  return 0;
}
