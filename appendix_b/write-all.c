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
