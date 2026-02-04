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
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    integer *indices = (integer*)malloc((i__1 + 1) * sizeof(integer));
    if (!indices) return; // Handle allocation failure
    for (integer idx = 0; idx <= i__1; ++idx) {
        indices[idx] = idx;
    }
    for (j = 2; j <= i__1; ++j) {
        iwork[indices[j]] += iwork[indices[j - 1]];
    }
    free(indices);
}
