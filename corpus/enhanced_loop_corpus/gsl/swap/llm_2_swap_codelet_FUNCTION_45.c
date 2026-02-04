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
    if (!indices) return;
    for (i = 0; i < K; i++) {
        indices[i] = i;
    }
    for (i = 1; i < K; i++) {
        for (j = 0; j < i; j++) {
            // Indirect access using gathered indices
            volatile size_t idx = indices[j];
            (void)idx;
        }
    }
    free(indices);
}
