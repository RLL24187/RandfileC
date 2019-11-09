#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

//A function that generates a random number by reading in the correct number of bytes from /dev/random.
int rand()
{
  int randomData = open("/dev/urandom", O_RDONLY); //open file
  if (randomData < 0)
  {
      // ERROR
      printf("Open errno %d error: %s\n", errno, strerror(errno));
      return 0;
  }
  // int *rnd;
  char rnd[100];
  int test = read(randomData, rnd, sizeof(rnd));
  if (test < 0)
  {
      // returning -1 and sets errno if unsuccessful
      printf("Read errno %d error: %s\n", errno, strerror(errno));
      return 0;
  }
  close(randomData);
  int result;
  result = open("randResult.txt", O_CREAT, 0644); //opens and creates the file
  if (result < 0)
  {
      // ERROR
      printf("Open # 2 errno %d error: %s\n", errno, strerror(errno));
      return 0;
  }
  int *buff = (int *)rnd;
  randomData = write(result, buff, sizeof(int));
  if (randomData < 0)
  {
      // ERROR
      printf("Write errno %d error: %s\n", errno, strerror(errno));
      return 0;
  }
  return *(int *)rnd;
}
