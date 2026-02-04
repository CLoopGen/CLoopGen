#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < N + 1; ++j) {
        for (size_t k = 0; k < 1; ++k) {
            ATp[j] = 0;
        }
    }
}
