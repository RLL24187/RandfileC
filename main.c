#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "randfile.h"

void printbar(){
  printf("============================================================================\n");
}
// A main function that:
// Populates an array with 10 random numbers generated by your random function (print out each value)
// If your program seems to stall at this step, it's possible that your computer doesn't have enough entropy and is waiting, you can read from /dev/urandom instead.
// Writes the array to a file
// Do not use a loop when writing to the file
// Reads that file into a different array
// Do not use a loop when reading from the file
// Prints out the contents of the second array to verify the random numbers are the same from step 1
// Remember to use good practices, like checking return values for errors
// Also remember to include a makefile that includes a separate run target
int main(){
  printbar();
  printf("Testing rand\n");
  printbar();

  int result = open("randResult.txt", O_CREAT | O_RDWR, 0664); //opens and creates the file
  printf("result: %d\n", result);
  if (result < 0)
  {
    // ERROR in opening
    printf("Open in main.c errno %d error: %s\n", errno, strerror(errno));
    return 0;
  }
  int rnd[11];
  int i; //counter
  for(i = 0; i < 10; i++){
    rnd[i] = rand();
    printf("Random #%d: %d\n", i, rnd[i]);
  }

  printbar();
  printf("Writing numbers to file...\n");
  int fd = write(result, rnd, sizeof(rnd));
  printf("fd: %d | sizeof(buff): %d\n", fd, sizeof(rnd));
  if (fd < 0)
  {
    // ERROR in writing
    printf("Write in main.c errno %d error: %s\n", errno, strerror(errno));
    return 0;
  }
  close(result);
  result = open("randResult.txt", O_RDONLY, 0664); //opens and creates the file
  printbar();
  printf("Reading numbers from file...\n");
  int buff[11];
  fd = read(result, buff, sizeof(buff));
  printf("fd: %d | sizeof(buff): %d\n", fd, sizeof(buff));
  if (fd < 0)
  {
    // ERROR in reading
    printf("Read in main.c errno %d error: %s\n", errno, strerror(errno));
    return 0;
  }

  printf("Verification that written values were the same:\n");
  for(i = 0; i < 10; i++){
    printf("Random #%d: %d\n", i, buff[i]);
  }
  printf("result: %d\n", result);
  close(result);
  return 0;
}
