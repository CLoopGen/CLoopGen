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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        t0 = ((in[0]) + (in[4])) >> 1;
        t4 = ((in[0]) - (in[4])) >> 1;
        t1 = t4;
        t4 = (t0 - in[8]) >> 1;
        t2 = (t0 + in[8]) >> 1;
        t3 = t4;
        out[0 * pitch] = t2;
        out[1 * pitch] = t3;
        t4 = (t1 - in[12]) >> 1;
        t2 = (t1 + in[12]) >> 1;
        t3 = t4;
        out[2 * pitch] = t2;
        out[3 * pitch] = t3;
    } else {
        out[0 * pitch] = 0;
        out[1 * pitch] = 0;
        out[2 * pitch] = 0;
        out[3 * pitch] = 0;
    }
    in++;
    out++;
}
}
