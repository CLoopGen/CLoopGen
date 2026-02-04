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
    if (p[i] > 0) {
        sump += p[i];
    }
    sumq += q[i] - 1;
}
}
