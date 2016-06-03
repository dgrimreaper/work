#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <omp.h>
#define GIGABYTE 1024LL * 1024LL * 1024LL
int main( int argc, char *argv[] ) {
  unsigned int milisec = 600000; // length of time to sleep, in miliseconds
  struct timespec req = {0};
  req.tv_sec = 0;
  req.tv_nsec = milisec * 1000000L;
  int size = 32;

if (argc >2) {
  std::cout<<"usage: "<< argv[0] <<" [n]\n";
  std::cout<<"where n is how many GB of memory to allocate\n";
  return -1;
} else if (argc ==2) {
  size = std::atoi(argv[1]);
} else {
}

  printf("Allocating %dGB of memory\n",size);

#pragma omp parallel default(shared)
{
#pragma omp for
for (int i = 0; i < size; i++) {
   void * m = malloc(GIGABYTE);
   memset(m,0,GIGABYTE);

}
}

   nanosleep(&req, (struct timespec *)NULL);
   std::cout<<"Finished\n";
   return 0;
}
