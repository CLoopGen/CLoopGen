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
    for (i = 0; i < nb_samples; i += 2) {
        dst[i] = (sptr[i] - 128) >> 0;
        if (i + 1 < nb_samples)
            dst[i + 1] = (sptr[i + 1] - 128) >> 0;
    }
}
