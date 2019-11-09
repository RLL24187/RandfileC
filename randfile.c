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
  else
  {
    // int *rnd;
    char rnd[100];
    int test = read(randomData, rnd, sizeof(*rnd));
    if (test < 0)
    {
        // returning -1 and sets errno if unsuccessful
        printf("Read errno %d error: %s\n", errno, strerror(errno));
        return 0;
    }
  }
}
