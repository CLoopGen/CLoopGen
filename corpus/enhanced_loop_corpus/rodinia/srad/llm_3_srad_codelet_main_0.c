#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nr;
extern int *iN;
extern int *iS;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int *index = (int*)malloc(Nr * sizeof(int));
    if (!index) return; // Handle allocation failure
    for (long j = 0; j < Nr; j++) {
        index[j] = j; // Identity permutation, could be randomized or reordered in practice
    }
    for (i = 0; i < Nr; i++) {
        int idx = index[i]; // Use indirect indexing
        iN[idx] = idx - 1;
        iS[idx] = idx + 1;
    }
    free(index);
}
