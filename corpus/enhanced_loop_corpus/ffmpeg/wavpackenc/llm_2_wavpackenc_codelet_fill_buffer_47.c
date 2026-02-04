#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int nb_samples;
extern int i;
extern  int32_t *sptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < nb_samples; i += 2) {
        if (i < nb_samples) {
            dst[i] = (sptr[i] - 0) >> 8;
        }
    }
}
