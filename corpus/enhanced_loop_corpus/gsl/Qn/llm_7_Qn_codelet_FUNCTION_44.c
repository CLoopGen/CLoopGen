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
        p[i] = p[i] + (q[i] % 2); // Introduce WAW and RAW: write after prior use of p[i], depends on q[i]
    }
}
