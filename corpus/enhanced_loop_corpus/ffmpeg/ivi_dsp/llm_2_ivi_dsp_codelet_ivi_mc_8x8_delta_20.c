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
    // Variant 1: Strided memory access with increased stride (access every 2nd element, unrolled by factor 2)
    for (i = 0; i < 8; i++, buf += dpitch, wptr += pitch, ref_buf += pitch) {
        for (j = 0; j < 8; j += 2) {
            if (j + 1 < 8) {
                // Process two elements with stride of 2
                buf[j]     += ((ref_buf[j] + ref_buf[j + 1] + wptr[j] + wptr[j + 1]) >> 2);
                buf[j + 1] += ((ref_buf[j + 1] + ref_buf[j + 2] + wptr[j + 1] + wptr[j + 2]) >> 2);
            } else {
                buf[j] += ((ref_buf[j] + ref_buf[j + 1] + wptr[j] + wptr[j + 1]) >> 2);
            }
        }
    }
}
