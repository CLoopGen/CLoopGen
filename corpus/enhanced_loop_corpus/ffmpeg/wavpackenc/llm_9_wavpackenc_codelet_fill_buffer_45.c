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
    int limit = nb_samples * 2;
    for (i = 0; i < limit; i++) {
        int index = i / 2;
        dst[index] = ((sptr[index] - 128) * 3 + (sptr[index] - 128)) >> 1;
        i++; 
    }
}
