#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array
    // Simulates indirect or gather-style access pattern via a permutation index
    integer *temp_idx = (integer*)malloc(i__1 * sizeof(integer));
    if (!temp_idx) return; // Handle allocation failure

    // Create a simple permutation: reverse order
    for (j = 1; j <= i__1; ++j) {
        temp_idx[j - 1] = i__1 - j + 1;
    }

    // Use indirect indexing to assign values in reverse access order
    for (j = 1; j <= i__1; ++j) {
        integer pos = temp_idx[j - 1];
        if (pos >= 1 && pos <= i__1) {
            indx[pos] = pos;
        }
    }

    free(temp_idx);
}
