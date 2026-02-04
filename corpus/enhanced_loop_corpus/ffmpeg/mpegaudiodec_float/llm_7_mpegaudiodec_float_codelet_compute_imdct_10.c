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
        int update_val = (j & 3) != 3 ? 1 : (4 * 18 - 3);
        for (i = 0; i < 18; i++) {
            int idx = 4 * i;
            buf[idx] = 0.0f;
            *(out_ptr + 32 * i) = buf[idx]; 
        }
        for (int k = 0; k < update_val; k++) {
            buf[k] = 0.0f;
        }
        buf += update_val;
    }
}
