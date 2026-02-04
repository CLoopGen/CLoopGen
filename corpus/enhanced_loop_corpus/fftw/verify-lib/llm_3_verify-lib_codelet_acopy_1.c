#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *c;
extern C *a;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    int *indices = (int*)malloc(n * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < n; ++j) {
        indices[j] = j; // Assume non-trivial reordering could be applied here
    }
    for (i = 0; i < n; ++i) {
        int idx = indices[i]; // Indirect access via index array
        ((c[idx])[0]) = ((a[idx])[0]);
        ((c[idx])[1]) = ((a[idx])[1]);
    }
    free(indices);
}
