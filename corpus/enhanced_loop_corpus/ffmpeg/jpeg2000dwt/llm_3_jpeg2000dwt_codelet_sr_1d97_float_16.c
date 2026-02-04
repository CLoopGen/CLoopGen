#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory access using pointer arithmetic
    // Reformulates array indexing into consecutive pointer traversal
    float *base = p + 2 * ((i0 >> 1) - 1);  // Base pointer at first relevant location
    int count = ((i1 >> 1) + 2) - ((i0 >> 1) - 1);
    for (i = 0; i < count; i++) {
        float *current = base + 2 * i;
        current[0] -= 0.443506867F * (current[-1] + current[1]); // still accesses 2*i-1, 2*i, 2*i+1 but via offset from base
    }
}
