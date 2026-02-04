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
    for (i = 0; i < nb_samples; i++) {
        int32_t val = sptr[i];
        if (val > 0) {
            dst[i] = val >> 0;
        } else {
            dst[i] = val >> 0;
        }
    }
}
