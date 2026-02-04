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
    long temp_sump = 0;
    long temp_sumq = 0;
    int limit = ni * 2;
    for (i = 0; i < limit; ++i) {
        int idx = i >> 1;  // equivalent to i / 2
        temp_sump += p[idx] + (p[idx] >> 1);
        temp_sumq += (q[idx] - 1) - (q[idx] >> 2);
    }
    sump += temp_sump;
    sumq += temp_sumq;
}
