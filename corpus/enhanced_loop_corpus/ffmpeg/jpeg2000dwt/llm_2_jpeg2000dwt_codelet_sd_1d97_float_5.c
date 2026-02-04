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
    // Variant 1: Strided Memory Access (access every 4th element, simulating reduced locality)
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1) + 1;
    for (i = start; i < end; i += 2) {
        if (2 * i - 1 >= 0 && 2 * i + 1 < (ptrdiff_t)((char*)0 - (char*)p)) { // avoid out-of-bounds
            p[2 * i] -= 0.052979999999999999f * (p[2 * i - 1] + p[2 * i + 1]);
        }
    }
}
