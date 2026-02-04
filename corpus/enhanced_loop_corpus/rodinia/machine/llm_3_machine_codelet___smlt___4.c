#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp;
extern double s;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using index array (simulating gather pattern)
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = j; // identity mapping for generality
    }
    for (i = 0; i < len; i++) {
        (*out++) = s * dp[indices[i]];
    }
    free(indices);
}
