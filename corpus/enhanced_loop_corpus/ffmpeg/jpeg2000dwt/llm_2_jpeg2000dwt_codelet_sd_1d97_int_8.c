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
    // Variant 1: Consecutive Memory Access (unrolled and restructured for sequential access)
    int start = (i0 >> 1) - 2;
    int end = (i1 >> 1) + 1;
    int *base = p + 2 * start;
    for (i = start; i < end; i++) {
        int temp = base[0] + base[4];  // p[2*i] + p[2*i+2]
        base[1] -= (103949LL * temp + (1 << 15)) >> 16;  // p[2*i+1]
        base += 2;  // Move to next logical pair: p[2*(i+1)]
    }
}
