#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *A;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulating gather pattern)
    int *indices = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) {
        indices[j] = n - 1 - j;  // Reverse indexing
    }
    for (i = 0; i < n; ++i) {
        ((A[indices[i]])[1]) = 0.;
    }
    free(indices);
}
