#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index permutation via pointer arithmetic
    int *idx = malloc(ni * sizeof(int));
    if (!idx) return; // Handle allocation failure
    for (i = 0; i < ni; ++i)
        idx[i] = i; // Identity permutation (could be randomized or reordered in practice)
    for (i = 0; i < ni; ++i)
        left[idx[i]] = q[idx[i]];
    free(idx);
}
