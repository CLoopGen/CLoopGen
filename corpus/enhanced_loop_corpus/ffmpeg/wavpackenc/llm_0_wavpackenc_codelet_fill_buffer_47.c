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
    int j;
    for (i = 0; i < nb_samples; i++) {
        for (j = 0; j < 1; j++) {
            dst[i] = (sptr[i] - 0) >> 8;
        }
    }
}
