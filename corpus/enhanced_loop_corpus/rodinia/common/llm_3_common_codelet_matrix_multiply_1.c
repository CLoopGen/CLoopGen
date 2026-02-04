#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *inputa;
extern float *inputb;
extern float *output;
extern int size;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index arrays
    // Simulate indirect addressing by precomputing access indices in auxiliary arrays
    // This mimics scenarios where data access patterns are non-regular or gathered from pointers
    int *index_i = (int*)malloc(size * sizeof(int));
    int *index_k = (int*)malloc(size * sizeof(int));
    int *index_j = (int*)malloc(size * sizeof(int));

    // Precompute linear indices for indirect access
    for (int idx = 0; idx < size; idx++) {
        index_i[idx] = idx;
        index_k[idx] = idx;
        index_j[idx] = idx;
    }

    for (i = 0; i < size; i++)
        for (k = 0; k < size; k++)
            for (j = 0; j < size; j++) {
                int a_idx = index_i[i] * size + index_k[k];
                int b_idx = index_k[k] * size + index_j[j];
                int out_idx = index_i[i] * size + index_j[j];
                output[out_idx] = inputa[a_idx] * inputb[b_idx];
            }

    free(index_i);
    free(index_k);
    free(index_j);
}
