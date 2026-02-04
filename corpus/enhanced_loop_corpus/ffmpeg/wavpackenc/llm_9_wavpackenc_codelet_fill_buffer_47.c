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
    int limit = nb_samples * 3;
    for (i = 0; i < limit; i++) {
        int idx = i / 3;
        int32_t val = sptr[idx] - 1;
        val = (val >> 8) + (val >> 4);
        dst[idx] = val;
    }
}
