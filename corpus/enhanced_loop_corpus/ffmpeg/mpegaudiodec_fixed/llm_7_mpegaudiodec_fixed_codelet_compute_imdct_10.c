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
for (j = sblimit; j < 32; j++) {
    out_ptr = sb_samples + j;
    for (i = 0; i < 18; i++) {
        int index = 4 * i;
        int val = buf[index];
        buf[index] = 0;
        *out_ptr = val;
        out_ptr += 32;
    }
    if ((j & 3) == 3) {
        buf += 4 * 18 - 3;
    } else {
        buf += 1;
    }
}
}
