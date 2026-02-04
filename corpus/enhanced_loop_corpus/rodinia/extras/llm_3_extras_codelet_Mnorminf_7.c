#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double tmp;
extern double max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with stride-like pattern)
    int *indices = (int*)malloc(len * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // Reverse access order
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i]; // Indirect access
        tmp = ((x[idx]) >= 0 ? (x[idx]) : -(x[idx]));
        if (max_val < tmp)
            max_val = tmp;
    }
    free(indices);
}
