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
    // Variant 1: Consecutive memory access with array base offset
    float *base = p - 2*(i0 >> 1);
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        int idx = 2 * i;
        base[2*i + 1] += 1.58613431F * (base[2*i] + base[2*i + 2]);
    }
}
