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
    // Variant 2: Strided memory access - traverse arrays in reverse order with stride of 2
    // This changes access pattern to non-consecutive and backward, affecting cache behavior
    for (i = 0; i < 8; i++, buf += dpitch, wptr += pitch, ref_buf += pitch) {
        for (j = 7; j >= 0; j -= 2) {
            buf[j] = (ref_buf[j] + wptr[j]) >> 1;
            if (j > 0) {
                buf[j-1] = (ref_buf[j-1] + wptr[j-1]) >> 1;
            }
        }
    }
}
