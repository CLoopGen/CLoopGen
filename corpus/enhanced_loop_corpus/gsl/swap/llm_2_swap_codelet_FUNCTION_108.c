#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (size_t i = 0; i < N + 1; i += 2)
        ATp[i] = 0;
    // Handle odd-sized N+1 if necessary
    if ((N + 1) % 2 == 1) {
        ATp[N] = 0;
    }
}
