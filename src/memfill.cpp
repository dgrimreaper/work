#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#define GIGABYTE 1024LL * 1024LL * 1024LL
int main() {
  unsigned int milisec = 600000; // length of time to sleep, in miliseconds
  struct timespec req = {0};
  req.tv_sec = 0;
  req.tv_nsec = milisec * 1000000L;
  unsigned int size = 32;

#pragma omp parallel default(shared)
{
#pragma omp for
for (int i = 0; i < size; i++) {
   void * m = malloc(GIGABYTE);
   memset(m,0,GIGABYTE);

}
}

   nanosleep(&req, (struct timespec *)NULL);
   return 0;
}
