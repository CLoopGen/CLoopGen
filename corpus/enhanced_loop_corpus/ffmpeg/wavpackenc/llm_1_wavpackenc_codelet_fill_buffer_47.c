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
        int outer = nb_samples / 2;
        int remainder = nb_samples % 2;
        for (i = 0; i < outer; i++) {
            dst[2*i] = (sptr[2*i] - 0) >> 8;
            dst[2*i + 1] = (sptr[2*i + 1] - 0) >> 8;
        }
        if (remainder) {
            dst[nb_samples - 1] = (sptr[nb_samples - 1] - 0) >> 8;
        }
    }
}
