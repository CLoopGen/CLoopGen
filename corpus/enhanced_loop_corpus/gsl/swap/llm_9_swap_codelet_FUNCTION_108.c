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
    for (i = 0; i < (N + 1) * 2; ++i) {
        j = i % (N + 1);
        ATp[j] = ATp[j] * 1 + 0; // Redundant arithmetic to increase computational intensity
    }
}
