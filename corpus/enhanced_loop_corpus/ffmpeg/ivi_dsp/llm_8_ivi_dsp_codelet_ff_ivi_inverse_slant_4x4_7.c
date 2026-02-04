#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int i;
extern  int32_t *src;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    if (!src[0] && !src[1] && !src[2] && !src[3] && !src[4] && !src[5] && !src[6] && !src[7]) {
        out[0] = out[1] = out[2] = out[3] = out[4] = out[5] = out[6] = out[7] = 0;
    } else {
        t0 = (src[0]) - (src[4]);
        t1 = (src[0]) + (src[4]);
        t2 = (t0);
        t0 = (((src[2]) + (src[6]) * 2 + 2) >> 2) + (src[2]);
        t3 = (((src[2]) * 2 - (src[6]) + 2) >> 2) - (src[6]);
        t4 = (t0);
        t0 = (t1) - (t4);
        t1 = (t1) + (t4);
        t4 = (t0);
        t0 = (t2) - (t3);
        t2 = (t2) + (t3);
        t3 = (t0);
        out[0] = (((t1) + 1) >> 1);
        out[1] = (((t2) + 1) >> 1);
        out[2] = (((t3) + 1) >> 1);
        out[3] = (((t4) + 1) >> 1);
        out[4] = (((t1 + t3) + 1) >> 1);
        out[5] = (((t2 + t4) + 1) >> 1);
        out[6] = (((t3 - t1) + 1) >> 1);
        out[7] = (((t4 - t2) + 1) >> 1);
    }
    src += 8;
    out += pitch;
}
}
