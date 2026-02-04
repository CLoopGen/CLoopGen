#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int16_t *out;
extern ptrdiff_t pitch;
extern  uint8_t *flags;
extern int i;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int t5;
extern int t6;
extern int t7;
extern int t8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (flags[i]) {
        int32_t temp_in[8];
        for (int j = 0; j < 8; j++) {
            temp_in[j] = in[j * 8];
        }
        t1 = (temp_in[0]) * 2;
        t5 = (temp_in[1]) * 2;
        t0 = ((t1) - (t5)) >> 1;
        t1 = ((t1) + (t5)) >> 1;
        t5 = (t0);
        t0 = ((t1) - (temp_in[2])) >> 1;
        t1 = ((t1) + (temp_in[2])) >> 1;
        t3 = (t0);
        t0 = ((t5) - (temp_in[3])) >> 1;
        t5 = ((t5) + (temp_in[3])) >> 1;
        t7 = (t0);
        t0 = ((t1) - (temp_in[4])) >> 1;
        t1 = ((t1) + (temp_in[4])) >> 1;
        t2 = (t0);
        t0 = ((t3) - (temp_in[5])) >> 1;
        t3 = ((t3) + (temp_in[5])) >> 1;
        t4 = (t0);
        t0 = ((t5) - (temp_in[6])) >> 1;
        t5 = ((t5) + (temp_in[6])) >> 1;
        t6 = (t0);
        t0 = ((t7) - (temp_in[7])) >> 1;
        t7 = ((t7) + (temp_in[7])) >> 1;
        t8 = (t0);
        int16_t *out_ptr = out;
        for (int k = 0; k < 8; k++) {
            out_ptr[k * pitch] = (int16_t)((int[]){t1, t2, t3, t4, t5, t6, t7, t8})[k];
        }
    } else {
        for (int k = 0; k < 8; k++) {
            out[k * pitch] = 0;
        }
    }
    in++;
    out++;
}
}
