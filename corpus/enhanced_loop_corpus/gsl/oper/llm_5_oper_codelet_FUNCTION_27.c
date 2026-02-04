#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - iterate over transposed indices to simulate stride-N access
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Access pattern now varies with outer loop on j, creating strided behavior if used with array[j + i*N]
        }
    }
}
