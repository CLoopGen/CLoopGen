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
    if (ni > 0) {
        sump += p[0];
        sumq += q[0] - 1;
        for (i = 1; i < ni; ++i) {
            long prev_p = p[i-1]; // Introduce artificial RAW dependency
            sump += p[i] + (prev_p & 0x1); // Use of previous value creates RAW
            sumq += q[i] - 1;
        }
    }
}
