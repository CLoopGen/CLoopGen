#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access simulation using an index remapping array
    // We precompute an access sequence (reverse order) to simulate indirect/non-sequential access
    // This changes the order of processing from ascending k to descending k
    // Simulates scenarios where dependencies or data layout require non-linear traversal

    // Allocate and initialize reverse index map
    int *index_map = (int*)malloc((n) * sizeof(int));
    for (int i = 1; i <= n - 1; i++) {
        index_map[i] = n - i;  // Reverse mapping: process from high to low
    }

    for (int idx = 1; idx <= n - 1; idx++) {
        k = index_map[idx];  // Indirect access via remapped index
        k_term *= y / (k * (n - k));
        sum1 += k_term;
    }

    free(index_map);
}
