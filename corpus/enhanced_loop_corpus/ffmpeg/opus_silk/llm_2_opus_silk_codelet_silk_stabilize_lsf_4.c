#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse, then handle remaining)
    // We simulate a strided pattern by processing elements in two passes with step size 2
    for (i = ((order - 2) % 2); i >= 0; i -= 2) {
        if (nlsf[i] > nlsf[i + 1] - min_delta[i + 1])
            nlsf[i] = nlsf[i + 1] - min_delta[i + 1];
    }
    for (i = ((order - 2) % 2 == 0 ? order - 3 : order - 4); i >= 1; i -= 2) {
        if (nlsf[i] > nlsf[i + 1] - min_delta[i + 1])
            nlsf[i] = nlsf[i + 1] - min_delta[i + 1];
    }
}
