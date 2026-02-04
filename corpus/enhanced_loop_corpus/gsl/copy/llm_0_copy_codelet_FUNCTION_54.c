#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(N * sizeof(size_t));
    for (i = 0; i < N; i++) {
        indices[i] = i;
    }
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            // Indirect access using an index array
            volatile size_t idx = indices[j];
            (void)idx;
        }
    }
    free(indices);
}
