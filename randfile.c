#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//A function that generates a random number by reading in the correct number of bytes from /dev/random.
int rand()
{
  int randomData = open("/dev/urandom", O_RDONLY); //open file
  if (randomData < 0)
    {
        // ERROR
        printf("errno %d error: %s\n, errno, strerror(errno));
        return 0;
    }
}
