#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect addressing by precomputing indices in reverse order
    // Since we cannot allocate dynamically without knowing size beforehand,
    // we assume maximum possible size is bounded by typical use of nmin/nmax.
    // Use stack-allocated array with conservative size limit
    const int MAX_SIZE = 1024;
    int indices[MAX_SIZE];
    int count = 0;

    // Precompute indices in descending order
    for (int temp_n = nmax; temp_n >= nmin && count < MAX_SIZE; temp_n--) {
        indices[count++] = temp_n - nmin;
    }

    // Traverse indirectly using the precomputed index list
    for (int i = 0; i < count; i++) {
        result_array[indices[i]] = 0.;
    }
}
