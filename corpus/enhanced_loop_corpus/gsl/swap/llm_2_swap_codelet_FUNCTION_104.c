#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (j = 0; j < M + 1; j += 2)
        ATp[j] = 0;
    if ((M + 1) % 2 == 1) {
        // Handle odd-sized array to ensure all elements are covered
        for (j = 1; j < M + 1; j += 2)
            ATp[j] = 0;
    }
}
