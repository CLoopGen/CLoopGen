#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = (M + 1) > 1000 ? 4 : 1;
    for (j = 0; j < M + 1; ++j) {
        ATp[j] = (int)((j * j + 3 * j + 2) % 100); // Increased arithmetic intensity
    }
}
