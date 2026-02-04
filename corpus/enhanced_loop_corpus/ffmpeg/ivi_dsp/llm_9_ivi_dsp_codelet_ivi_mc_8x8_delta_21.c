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
for (i = 0; i < 4; i++, buf += dpitch * 2, ref_buf += pitch * 2) {
    for (j = 0; j < 8; j++) {
        int16_t temp = (buf[j] + ref_buf[j]) >> 1; // Increased arithmetic intensity
        buf[j] = temp;
    }
    // Unroll second iteration manually
    for (j = 0; j < 8; j++) {
        int16_t temp = (buf[j + dpitch] + ref_buf[j + pitch]) >> 1;
        buf[j + dpitch] = temp;
    }
}
}
