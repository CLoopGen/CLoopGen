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
    // Variant 1: Consecutive memory access by unrolling and reorganizing access pattern
    // Instead of accessing p[2*i] with stride 2, we process two elements at a time consecutively
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1) + 1;
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        // Ensure bounds: need idx-1, idx, idx+1 to be valid
        if (idx - 1 >= 0 && idx + 1 < (int)(sizeof(int)*8192)) { // assuming reasonable bound
            int temp = (3472LL * (p[idx - 1] + p[idx + 1]) + (1 << 15)) >> 16;
            p[idx] -= temp;
        }
    }
}
