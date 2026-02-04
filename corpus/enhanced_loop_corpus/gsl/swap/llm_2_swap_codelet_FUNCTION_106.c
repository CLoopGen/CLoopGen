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
    // Variant 1: Strided memory access with stride of 2
    size_t j;
    size_t stride = 2;
    for (j = 0; j < M; j += stride) {
        if (j < M) w[j] = ATp[j];
        if (j + 1 < M) w[j + 1] = ATp[j + 1];
    }
}
