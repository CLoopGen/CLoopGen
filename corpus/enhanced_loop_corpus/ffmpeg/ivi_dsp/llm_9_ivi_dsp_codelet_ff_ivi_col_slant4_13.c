#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int16_t *out;
extern ptrdiff_t pitch;
extern  uint8_t *flags;
extern int i;
extern int row2;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    if (flags[i]) {
        t1 = (in[0]) + (in[8]);
        t0 = (in[0]) - (in[8]);
        t2 = t0;
        t0 = (((in[4]) + (in[12]) + 1) >> 1);
        t3 = (((in[4]) - (in[12]) + 1) >> 1);
        t1 = (t1) + (t0);
        t2 = (t2) + (t3);
        out[0] = ((t1 + 1) >> 1);
        out[pitch] = ((t2 + 1) >> 1);
    } else {
        out[0] = out[pitch] = 0;
    }
    in += 2;
    out += 2;
}
}
