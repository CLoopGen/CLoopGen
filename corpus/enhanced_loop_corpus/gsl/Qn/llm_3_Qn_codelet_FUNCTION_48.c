#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Introduce an auxiliary index array to reorder memory accesses
    // This simulates indirect or gather-style access patterns

    // Allocate and create an index mapping: reverse order access
    int *idx = (int*)malloc(ni * sizeof(int));
    if (!idx) return; // Handle allocation failure

    for (int j = 0; j < ni; ++j) {
        idx[j] = ni - 1 - j; // reverse indexing
    }

    for (i = 0; i < ni; ++i) {
        int index = idx[i]; // indirect access via index map
        left[index] = ni - index + 1;
        right[index] = (index <= h) ? ni : ni - (index - h);
    }

    free(idx);
}
