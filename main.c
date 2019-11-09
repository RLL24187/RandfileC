#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "randfile.h"

void printbar(){
  printf("============================================================================\n");
}
int main(){
  printbar();
  printf("Testing rand\n");
  printbar();
  printf("Random number generated: %d\n", rand());
}
