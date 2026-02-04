#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *p;
extern int *q;
extern int i;
extern long sump;
extern long sumq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long local_sum = 0;
    for (i = 0; i < ni; ++i) {
        local_sum += p[i] + q[i] - 1;
    }
    sump += local_sum;
    sumq = sump - ni;
}
