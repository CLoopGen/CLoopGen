#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = i0 >> 1;
    int end = (i1 >> 1) - 2;
    for (i = start; i < end; i++) {
        p[2 * i + 1] += 1.58613431F * (p[2 * i] + p[2 * i + 2]);
        p[2 * i + 3] += 1.1F * (p[2 * i + 2] + p[2 * i + 4]) + 0.01F * p[2 * i + 1];
        p[2 * i + 5] *= 1.05F;
    }
}
