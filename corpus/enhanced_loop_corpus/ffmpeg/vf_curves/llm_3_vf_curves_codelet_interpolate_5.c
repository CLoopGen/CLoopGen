#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate arbitrary access order
    int *indices = (int*)malloc(n * sizeof(int));
    for (int j = 0; j < n - 1; j++) {
        indices[j] = n - 2 - j;  // Reverse order indices
    }
    for (int j = 0; j < n - 1; j++) {
        i = indices[j];
        r[i] = r[i] - matrix[i][2] * r[i + 1];
    }
    free(indices);
}
