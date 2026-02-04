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
        ATp[j] = 0;
        if (j > 0)
            ATp[j] += ATp[j - 1]; // Introduce RAW dependency: current iteration reads previous write
    }
}
