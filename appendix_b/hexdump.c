#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  unsigned char buffer[16];
  size_t offset = 0;
  size_t bytes_read;
  int i;

  int fd = open(argv[1], O_RDONLY);

  //Read file one chunk at a time until READ reads less than what we asked
  //This means we've reached EOF
  
  do
  {
    bytes_read = read(fd, buffer, sizeof(buffer));
    //print offset followed by the bytes read
    printf("0x%06x : ", offset);
    for (i=0; i<bytes_read; ++i)
    {
      printf("%02x ", buffer[i]);
    }
    printf("\n");
    offset += bytes_read;
  }
  while (bytes_read == sizeof(buffer));

  close(fd);
  return 0;
}
