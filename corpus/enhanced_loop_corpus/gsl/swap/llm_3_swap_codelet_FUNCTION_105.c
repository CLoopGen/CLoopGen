#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nz;
extern int *Ai;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(nz * sizeof(size_t));
    if (!indices) return;
    for (j = 0; j < nz; ++j)
        indices[j] = j;
    for (j = 0; j < nz; ++j) {
        size_t idx = indices[j];
        ATp[Ai[idx]]++;
    }
    free(indices);
}
