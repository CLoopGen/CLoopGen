#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **chrUSrcPtr;
extern  int16_t **tmpU;
extern int neg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reversed traversal with offset-based indirect access
    // Traverse tmpU in reverse order consecutively, mapping to a shifted index in chrUSrcPtr
    // This creates a different memory access pattern while maintaining valid pointer assignments
    for (i = 0; i < neg; i++) {
        int src_idx = (neg - 1 - i) % neg;  // Reverse walk through source indices
        tmpU[i] = chrUSrcPtr[src_idx];
    }
}
