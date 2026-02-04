#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (i0 >> 1); i < (i1 >> 1) - 3; i += 4) {
        p[2 * i]     += (29066LL * (p[2 * i - 1] + p[2 * i + 1])     + (1 << 15)) >> 16;
        p[2 * (i+1)] += (29066LL * (p[2 * (i+1) - 1] + p[2 * (i+1) + 1]) + (1 << 15)) >> 16;
        p[2 * (i+2)] += (29066LL * (p[2 * (i+2) - 1] + p[2 * (i+2) + 1]) + (1 << 15)) >> 16;
        p[2 * (i+3)] += (29066LL * (p[2 * (i+3) - 1] + p[2 * (i+3) + 1]) + (1 << 15)) >> 16;
    }
    // Handle remaining iterations
    for (; i < (i1 >> 1); i++) {
        p[2 * i] += (29066LL * (p[2 * i - 1] + p[2 * i + 1]) + (1 << 15)) >> 16;
    }
}
