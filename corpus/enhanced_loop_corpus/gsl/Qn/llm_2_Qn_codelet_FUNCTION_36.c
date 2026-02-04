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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < ni; i += 2) {
        sump += p[i];
        sumq += q[i] - 1;
        if (i + 1 < ni) {
            sump += p[i + 1];
            sumq += q[i + 1] - 1;
        }
    }
}
