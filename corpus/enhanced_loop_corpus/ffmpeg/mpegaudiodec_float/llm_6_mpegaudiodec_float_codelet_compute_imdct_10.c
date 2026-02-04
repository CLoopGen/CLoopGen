#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *sb_samples;
extern float *out_ptr;
extern float *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = sblimit; j < 32; j++) {
        out_ptr = sb_samples + j;
        int offset = j & 3;
        for (i = 0; i < 18; i++) {
            float temp = buf[4 * i];
            *out_ptr = temp;
            buf[4 * i] = 0.0f;
            out_ptr += 32;
        }
        if ((offset != 3)) {
            buf++;
        } else {
            buf += (4 * 18 - 3);
        }
    }
}
