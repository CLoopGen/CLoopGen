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
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        t1 = (in[0]) * 2;
        t5 = (in[8]) * 2;
        t0 = ((t1) - (t5)) >> 1;
        t1 = ((t1) + (t5)) >> 1;
        t5 = (t0);
        t0 = ((t1) - (in[16])) >> 1;
        t1 = ((t1) + (in[16])) >> 1;
        t3 = (t0);
        t0 = ((t5) - (in[24])) >> 1;
        t5 = ((t5) + (in[24])) >> 1;
        t7 = (t0);
        out[0 * pitch] = (t1);
        out[1 * pitch] = (t3);
        out[2 * pitch] = (t5);
        out[3 * pitch] = (t7);
    } else {
        out[0 * pitch] = out[1 * pitch] = out[2 * pitch] = out[3 * pitch] = 0;
    }
    in += 2;
    out += 2;
}
}
