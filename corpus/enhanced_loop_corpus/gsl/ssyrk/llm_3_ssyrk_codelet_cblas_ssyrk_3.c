#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect (gather-like) memory access via an index array to simulate irregular access
    // Simulate indirect access using precomputed column indices (within bounds)
    int *indices = (int*)malloc((N * (N + 1)) / 2 * sizeof(int)); // Max possible elements in lower triangle
    int offset = 0;
    for (int ii = 0; ii < N; ii++) {
        for (int jj = 0; jj <= ii; jj++) {
            indices[offset++] = ldc * ii + jj;
        }
    }
    // Now traverse all collected indices consecutively (converting nested loop into flat indirect access)
    for (int k = 0; k < offset; k++) {
        C[indices[k]] *= beta;
    }
    free(indices);
}
