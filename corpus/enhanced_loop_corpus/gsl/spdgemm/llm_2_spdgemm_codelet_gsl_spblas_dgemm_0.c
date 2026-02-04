#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (j = 0; j < M; j += 2)
        w[j] = 0;
    // Handle odd-sized M if necessary
    if (M % 2 == 1) {
        w[M - 1] = 0;
    }
}
