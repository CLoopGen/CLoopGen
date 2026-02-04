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
    int32_t temp;
    for (i = 0; i < nb_samples; i++) {
        temp = sptr[i] - 0;
        dst[i] = temp >> 8;
    }
}
