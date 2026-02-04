#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(K * sizeof(size_t));
    for (i = 0; i < K; i++) {
        indices[i] = i;
    }
    for (i = 0; i < K; i++) {
        for (j = i + 1; j < K; j++) {
            // Simulate indirect access using index array
            size_t idx1 = indices[i];
            size_t idx2 = indices[j];
            // Dummy operation to ensure usage
            volatile size_t dummy = idx1 + idx2;
        }
    }
    free(indices);
}
