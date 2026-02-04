#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < N + 1; ++j) {
        size_t index = N - j; // Reverse access pattern, no loop-carried dependency
        if (index <= N)
            ATp[index] = 0;
        // Eliminated sequential dependency; accesses are independent across iterations
    }
}
