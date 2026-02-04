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
for (i = 0; i < 8; i++) {
    if (flags[i % 4]) {
        t4 = ((in[0]) - (in[4])) >> 1;
        t0 = ((in[0]) + (in[4])) >> 1;
        t1 = t4;
        t4 = ((t0) - (in[8])) >> 1;
        t2 = ((t0) + (in[8])) >> 1;
        t3 = t4;
        out[0 * pitch] = t2;
        out[1 * pitch] = t3;
        t4 = ((t1) - (in[12])) >> 1;
        t2 = ((t1) + (in[12])) >> 1;
        t3 = t4;
        out[2 * pitch] = t2;
        out[3 * pitch] = t3;
        t4 = ((in[2]) - (in[6])) >> 1;
        t0 = ((in[2]) + (in[6])) >> 1;
        t1 = t4;
        t4 = ((t0) - (in[10])) >> 1;
        t2 = ((t0) + (in[10])) >> 1;
        t3 = t4;
        out[4 * pitch] = t2;
        out[5 * pitch] = t3;
        t4 = ((t1) - (in[14])) >> 1;
        t2 = ((t1) + (in[14])) >> 1;
        t3 = t4;
        out[6 * pitch] = t2;
        out[7 * pitch] = t3;
    } else {
        for (int j = 0; j < 8; j++) {
            out[j * pitch] = 0;
        }
    }
    in += 2;
    out += 2;
}
}
