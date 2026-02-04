#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < 1; ++i) {
        for (size_t k = 0; k < N + 1; ++k)
            ATp[k] = 0;
    }
}
