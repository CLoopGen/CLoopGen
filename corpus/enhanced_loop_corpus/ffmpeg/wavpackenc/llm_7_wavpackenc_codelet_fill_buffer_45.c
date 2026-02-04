#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int nb_samples;
extern int i;
extern  int8_t *sptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nb_samples > 0) {
        dst[0] = (sptr[0] - 128) >> 0;
        for (i = 1; i < nb_samples; i++) {
            dst[i] = (sptr[i] - 128) >> 0;
            dst[i] += dst[i-1]; // Introduce WAW and RAW loop-carried dependency
        }
    }
}
