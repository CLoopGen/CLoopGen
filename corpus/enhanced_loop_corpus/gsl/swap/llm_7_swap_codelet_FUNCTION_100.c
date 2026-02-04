#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k;
    for (k = 0; k < N + 1; ++k) {
        size_t index1 = k;
        size_t index2 = N - k; // Reverse indexing introduces non-trivial WAW potential
        if (index1 != index2) {
            ATp[index1] = 0;
            ATp[index2] = 0; // Eliminate loop-carried dependency by writing to independent locations
        } else {
            ATp[index1] = 0; // Middle element when N is even
        }
    }
}
