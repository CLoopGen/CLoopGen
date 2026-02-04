#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed offset table (simulated indirect indexing)
    integer indices[2] = {0, 1};
    for (j = 2; j <= i__1; ++j) {
        integer prev_idx = j + indices[1] - 1; // effectively j - 1 via lookup
        iwork[j] += iwork[prev_idx];
    }
}
