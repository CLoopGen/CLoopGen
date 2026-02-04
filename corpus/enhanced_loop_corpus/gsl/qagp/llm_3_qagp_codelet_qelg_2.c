#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *epstab;
extern  size_t newelm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc((newelm + 1) * sizeof(size_t));
    if (!indices) return;
    for (size_t j = 0; j <= newelm; j++) {
        indices[j] = j;
    }
    for (i = 0; i <= newelm; i++) {
        size_t idx = indices[i];
        epstab[idx * 2] = epstab[idx * 2 + 2];
    }
    free(indices);
}
