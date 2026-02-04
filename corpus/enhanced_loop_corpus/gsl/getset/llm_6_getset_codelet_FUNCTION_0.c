#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < N; j++) {
        unsigned int k = j; // Introduce RAW dependency: k depends on loop index j
        k += 1;             // WAW: write after write to same local variable
        if (k % 2 == 0) {
            k *= 3;
        }
    }
}
