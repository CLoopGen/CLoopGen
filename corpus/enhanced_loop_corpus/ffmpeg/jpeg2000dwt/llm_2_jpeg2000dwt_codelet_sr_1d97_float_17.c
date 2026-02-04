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
    // Variant 1: Consecutive memory access by reindexing to eliminate strided access
    float *base_p = p + 2 * ((i0 >> 1) - 1);
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1) + 1;
    int len = end - start;
    for (int idx = 0; idx < len; idx++) {
        base_p[2 * idx + 1] -= 0.882911086F * (base_p[2 * idx] + base_p[2 * idx + 2]);
    }
}
