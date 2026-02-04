#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t len;
extern uint32_t stride;
extern float c;
extern float s;
extern float *Xptr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, reorganize data access to use consecutive indices.
    // Assume that the effective stride is folded into index arithmetic with a base shift.
    float *base = Xptr - (len - 1); // Adjust base pointer to simulate reversed traversal
    for (i = len - 2 * stride - 1; i >= 0; i--) {
        ptrdiff_t idx = i;
        float x1 = base[idx];
        float x2 = base[idx + stride];
        base[idx + stride] = c * x2 + s * x1;
        base[idx] = c * x1 - s * x2;
    }
}
