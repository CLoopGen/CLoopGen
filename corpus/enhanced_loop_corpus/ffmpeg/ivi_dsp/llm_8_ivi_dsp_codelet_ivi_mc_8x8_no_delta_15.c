#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;
extern  int16_t *wptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count
    for (i = 0; i < 4; i++, buf += dpitch, wptr += pitch, ref_buf += pitch)
        for (j = 0; j < 8; j++) {
            int16_t avg = (ref_buf[j] + wptr[j]) >> 1;
            int16_t diff = ref_buf[j] - wptr[j];
            int16_t penalty = (diff > 0) ? (diff >> 2) : (-diff >> 2);
            buf[j] = avg - penalty;
        }
}
