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
    size_t stride = 2;
    for (j = 0; j < nz; j += stride) {
        if (j + stride - 1 < nz) {
            ATp[Ai[j]]++;
            ATp[Ai[j + 1]]++;
        } else if (j < nz) {
            ATp[Ai[j]]++;
        }
    }
}
