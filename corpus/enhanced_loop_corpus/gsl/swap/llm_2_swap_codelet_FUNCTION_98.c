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
    size_t stride = 2;
    for (j = 0; j < M; j += stride) {
        if (j + 0 < M) w[j + 0] = ATp[j + 0];
        if (j + 1 < M) w[j + 1] = ATp[j + 1];
    }
}
