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
    if (nb_samples > 0) {
        dst[0] = (sptr[0] - 0) >> 8;
        for (i = 1; i < nb_samples; i++) {
            dst[i] = (sptr[i] - 0 + dst[i-1]) >> 8;
        }
    }
}
