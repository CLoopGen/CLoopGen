#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(M * sizeof(int));
    if (!indices) return;
    for (size_t idx = 0; idx < M; ++idx)
        indices[idx] = idx;
    for (j = 0; j < M; ++j) {
        size_t idx = indices[j];
        w[idx] = ATp[idx];
    }
    free(indices);
}
