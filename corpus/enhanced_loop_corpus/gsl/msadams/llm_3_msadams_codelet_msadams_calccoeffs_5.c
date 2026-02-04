#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern double pc[];
extern double *ordp2coeff;
extern size_t i;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array
    // Simulate indirect access via a precomputed permutation (reverse order access)
    // Assume we have a static reverse index map for simplicity, within bounds of ord+1
    size_t n = ord + 1;
    for (i = 0; i < n; i++) {
        size_t rev_index = n - 1 - i;  // Reverse traversal: indirect access pattern
        *ordp2coeff += s * pc[rev_index] / (rev_index + 2);
        s = -s;
    }
}
