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
    for (i = 0; i < ni; ++i) {
        sumq += q[i] - 1;
        sump += p[i];
        // Introduce artificial loop-carried dependency by making sumq update depend on previous sump (WAW-like pattern across iterations)
        if (i > 0 && p[i] > 0) {
            sumq += sump - p[i-1];  // Additional read of sump creates extended data dependency
        }
    }
}
