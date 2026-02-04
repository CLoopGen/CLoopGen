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
    if (N == 0) return;
    size_t j = 0;
    w[0] = ATp[0];
    for (j = 1; j < N; ++j) {
        w[j] = ATp[j] + w[j-1] - ATp[j-1]; // Introduces RAW dependency: w[j-1] read after write in previous iteration
    }
}
