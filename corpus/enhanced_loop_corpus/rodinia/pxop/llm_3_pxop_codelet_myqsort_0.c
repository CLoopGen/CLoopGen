#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *a;
extern int i;
extern int j;
extern int tmp;
extern int v;
extern int numswaps;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect array access via index remapping using a lookup table (simulated with pointer arithmetic)
    // Introduces indirect memory access pattern: values accessed through an offset map.
    // Simulate small fixed-size local indirection buffer for indices (avoids dynamic allocation)
    int indices[1024]; // Assume problem size within limit
    int n = 1024;     // Assume size
    for (int k = 0; k < n; k++) {
        indices[k] = k;
    }

    int ii = 0, jj = n - 1;
    for (;;) {
        ii++;
        jj--;
        if (ii >= jj) break;

        int idx_i = indices[ii];
        int idx_j = indices[jj];

        if (a[idx_i] < v) continue;
        if (a[idx_j] > v) continue;

        if (idx_i >= idx_j) break;

        tmp = a[idx_i];
        a[idx_i] = a[idx_j];
        a[idx_j] = tmp;
        numswaps++;
    }
}
