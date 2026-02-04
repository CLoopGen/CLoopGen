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
    size_t stride = 1;
    for (j = 0; j < M; j++) {
        w[j] = ATp[j];
        for (size_t k = 0; k < stride && j > 0; k++) {
            w[j] += w[j - 1];
        }
    }
}
