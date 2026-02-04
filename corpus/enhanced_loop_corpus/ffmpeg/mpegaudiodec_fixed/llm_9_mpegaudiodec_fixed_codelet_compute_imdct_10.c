#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sb_samples;
extern int *out_ptr;
extern int *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = sblimit; j < 32; j += 2) {
    for (i = 0; i < 9; i++) {
        out_ptr = sb_samples + j;
        *out_ptr = buf[8 * i];
        buf[8 * i] = 0;
        out_ptr += 32;
        if (j + 1 < 32) {
            out_ptr = sb_samples + j + 1;
            *out_ptr = buf[8 * i + 4];
            buf[8 * i + 4] = 0;
            out_ptr += 32;
        }
    }
    buf += (j & 3) >= 2 ? (4 * 18 - 6) : 2;
}
}
