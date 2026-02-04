#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // This changes the access pattern from sequential to strided (every other element)
    for (i = 0; i < subframe_size + (143 + 8 + 1); i += 2) {
        if (i < subframe_size + (143 + 8 + 1)) {
            tmp |= ((residual[i]) >= 0 ? (residual[i]) : (-(residual[i])));
        }
    }
}
