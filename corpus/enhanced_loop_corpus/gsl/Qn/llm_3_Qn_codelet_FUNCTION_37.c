#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index permutation via pointer arithmetic
    int *idx = (int*)malloc(ni * sizeof(int));
    if (!idx) return; // Handle allocation failure
    for (i = 0; i < ni; ++i)
        idx[i] = i;
    // Simulate a simple indirect pattern (reverse order access)
    for (i = 0; i < ni; ++i) {
        int j = ni - 1 - i; // reverse index
        right[idx[j]] = p[idx[j]];
    }
    free(idx);
}
