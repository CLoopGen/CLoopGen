#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern int *w;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; i < N; i += stride) {
        if (i + 1 < N) {
            w[i] = ATp[i];
            w[i + 1] = ATp[i + 1];
        } else {
            w[i] = ATp[i];
        }
    }
}
