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
ptrdiff_t indices[4] = {0, 4, 8, 12};
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        t4 = ((in[indices[0]]) - (in[indices[1]])) >> 1;
        t0 = ((in[indices[0]]) + (in[indices[1]])) >> 1;
        t1 = t4;
        t4 = ((t0) - (in[indices[2]])) >> 1;
        t2 = ((t0) + (in[indices[2]])) >> 1;
        t3 = t4;
        out[0 * pitch] = (int16_t)t2;
        out[1 * pitch] = (int16_t)t3;
        t4 = ((t1) - (in[indices[3]])) >> 1;
        t2 = ((t1) + (in[indices[3]])) >> 1;
        t3 = t4;
        out[2 * pitch] = (int16_t)t2;
        out[3 * pitch] = (int16_t)t3;
    } else {
        out[0 * pitch] = out[1 * pitch] = out[2 * pitch] = out[3 * pitch] = 0;
    }
    in++;
    out += 1;
}
}
