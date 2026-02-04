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
for (i = 0; i < 16; i += 2) {
    if (flags[i % 8]) {
        t1 = in[0] * 2;
        t5 = in[8] * 2;
        t0 = (t1 - t5) >> 1;
        t1 = (t1 + t5) >> 1;
        t5 = t0;
        t0 = (t1 - in[16]) >> 1;
        t1 = (t1 + in[16]) >> 1;
        t3 = t0;
        t0 = (t5 - in[24]) >> 1;
        t5 = (t5 + in[24]) >> 1;
        t7 = t0;
        t0 = (t1 - in[32]) >> 1;
        t1 = (t1 + in[32]) >> 1;
        t2 = t0;
        t0 = (t3 - in[40]) >> 1;
        t3 = (t3 + in[40]) >> 1;
        t4 = t0;
        t0 = (t5 - in[48]) >> 1;
        t5 = (t5 + in[48]) >> 1;
        t6 = t0;
        t0 = (t7 - in[56]) >> 1;
        t7 = (t7 + in[56]) >> 1;
        t8 = t0;

        out[0 * pitch] = t1;
        out[1 * pitch] = t2;
        out[2 * pitch] = t3;
        out[3 * pitch] = t4;
        out[4 * pitch] = t5;
        out[5 * pitch] = t6;
        out[6 * pitch] = t7;
        out[7 * pitch] = t8;

        if (flags[(i + 1) % 8]) {
            t1 = in[1] * 2;
            t5 = in[9] * 2;
            t0 = (t1 - t5) >> 1;
            t1 = (t1 + t5) >> 1;
            t5 = t0;
            t0 = (t1 - in[17]) >> 1;
            t1 = (t1 + in[17]) >> 1;
            t3 = t0;
            t0 = (t5 - in[25]) >> 1;
            t5 = (t5 + in[25]) >> 1;
            t7 = t0;
            t0 = (t1 - in[33]) >> 1;
            t1 = (t1 + in[33]) >> 1;
            t2 = t0;
            t0 = (t3 - in[41]) >> 1;
            t3 = (t3 + in[41]) >> 1;
            t4 = t0;
            t0 = (t5 - in[49]) >> 1;
            t5 = (t5 + in[49]) >> 1;
            t6 = t0;
            t0 = (t7 - in[57]) >> 1;
            t7 = (t7 + in[57]) >> 1;
            t8 = t0;

            out[8 * pitch] = t1;
            out[9 * pitch] = t2;
            out[10 * pitch] = t3;
            out[11 * pitch] = t4;
            out[12 * pitch] = t5;
            out[13 * pitch] = t6;
            out[14 * pitch] = t7;
            out[15 * pitch] = t8;
        } else {
            for (int j = 8; j < 16; j++) {
                out[j * pitch] = 0;
            }
        }
    } else {
        for (int j = 0; j < 16; j++) {
            out[j * pitch] = 0;
        }
    }
    in += 2;
    out += 2;
}
}
