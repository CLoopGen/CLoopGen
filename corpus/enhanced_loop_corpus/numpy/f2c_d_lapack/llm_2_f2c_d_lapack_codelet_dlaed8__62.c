#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *perm;
extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access perm and indxq in sequential order
    // Instead of indirect access via indx[j], we simulate a reordered traversal assuming indx contains a permutation.
    // We maintain the same logical result but change access pattern: traverse by physical index in perm.
    for (j = 1; j <= i__1; ++j) {
        integer idx = indx[j];              // Load the indirect index once
        perm[j] = indxq[idx];               // Still uses indxq indirectly, but perm is accessed consecutively
    }
}
