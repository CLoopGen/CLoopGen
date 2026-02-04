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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing j = 0..7 in order, access elements with a stride of 2 (even indices first, then odd)
    for (i = 0; i < 8; i++, buf += dpitch, wptr += pitch, ref_buf += pitch) {
        for (j = 0; j < 8; j += 2)
            (buf[j]) = ((ref_buf[j] + ref_buf[j + 1] + wptr[j] + wptr[j + 1]) >> 2);
        for (j = 1; j < 7; j += 2)
            (buf[j]) = ((ref_buf[j] + ref_buf[j + 1] + wptr[j] + wptr[j + 1]) >> 2);
    }
}
