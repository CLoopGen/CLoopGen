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
    for (i = 0; i < 64; i++, ((i % 8) == 7) ? (buf += dpitch, wptr += pitch, ref_buf += pitch) : 0) // Flattened 2D iteration into single loop
        (buf[i % 8]) += ((ref_buf[i % 8] + ref_buf[i % 8 + 1] + wptr[i % 8] + wptr[i % 8 + 1]) >> 2);
}
