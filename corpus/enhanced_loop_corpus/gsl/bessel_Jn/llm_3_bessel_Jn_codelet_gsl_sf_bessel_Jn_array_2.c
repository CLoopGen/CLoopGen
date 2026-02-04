#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    // Simulate indirect access by reversing the effective order of writes
    int *indices = (int*)malloc((nmax - nmin + 1) * sizeof(int));
    if (!indices) return; // Handle malloc failure
    int len = nmax - nmin + 1;
    // Create reversed index mapping: write from end to start indirectly
    for (int i = 0; i < len; i++) {
        indices[i] = len - 1 - i; // reverse order
    }
    // Use indirect addressing via lookup
    for (n = nmax; n >= nmin; n--) {
        int idx = indices[n - nmin]; // indirect index
        result_array[idx] = 0.;
    }
    free(indices);
}
