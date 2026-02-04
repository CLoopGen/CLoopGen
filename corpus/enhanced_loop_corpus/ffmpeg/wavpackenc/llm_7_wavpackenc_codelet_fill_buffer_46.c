#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int nb_samples;
extern int i;
extern  int16_t *sptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nb_samples; i++) {
        dst[i] = (sptr[i] - sptr[i-1]) >> 0;
    }
    if (nb_samples > 0) {
        dst[0] = sptr[0];
    }
}
