#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern int xbit[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping table
    // Use a precomputed index permutation to write elements in shuffled order
    static const int perm_index[31] = {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29
    };
    for (k = 0; k < 31; ++k) {
        int mapped_idx = perm_index[k];
        xbit[mapped_idx] = i % 2;
        i /= 2;
    }
}
