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
for (i = 0; i < 2; i++) {
    if (!src[0] && !src[1]) {
        out[0] = out[1] = 0;
    } else {
        t0 = (src[0]) + (src[1]);
        t1 = (src[0]) - (src[1]);
        t2 = (((src[0]) + 1) >> 1);
        t3 = (((src[1]) + 1) >> 1);
        t4 = (t0 + t1 + 1) >> 1;
        out[0] = (((t0) + 1) >> 1);
        out[1] = (((t1) + 1) >> 1);
    }
    src += 2;
    out += pitch;
}
}
