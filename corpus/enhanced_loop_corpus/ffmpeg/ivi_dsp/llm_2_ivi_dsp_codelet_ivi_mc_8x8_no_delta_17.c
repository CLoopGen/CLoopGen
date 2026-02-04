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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 2nd element, unroll by 2)
    for (i = 0; i < 8; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 0; j < 8; j += 2) {
            if (j + 1 < 8) {
                buf[j]     = ref_buf[j];
                buf[j + 1] = ref_buf[j + 1];
            } else {
                buf[j] = ref_buf[j];
            }
        }
    }
}
