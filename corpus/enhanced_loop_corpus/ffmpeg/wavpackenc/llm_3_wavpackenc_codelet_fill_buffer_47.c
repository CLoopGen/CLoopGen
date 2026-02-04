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
    // Variant 2: Consecutive reverse-order traversal from end to start
    for (i = nb_samples - 1; i >= 0; i--) {
        dst[i] = (sptr[i] - 0) >> 8;
    }
}
