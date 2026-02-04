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
    int32_t temp_in0 = in[0];
    int32_t temp_in4 = in[4];
    int32_t temp_in8 = in[8];
    int32_t temp_in12 = in[12];
    if (flags[i]) {
        t0 = (temp_in0 + temp_in4) >> 1;
        t1 = (temp_in0 - temp_in4) >> 1;
        t2 = (t0 + temp_in8) >> 1;
        t3 = (t0 - temp_in8) >> 1;
        out[0 * pitch] = t2;
        out[1 * pitch] = t3;
        t2 = (t1 + temp_in12) >> 1;
        t3 = (t1 - temp_in12) >> 1;
        out[2 * pitch] = t2;
        out[3 * pitch] = t3;
    } else {
        out[0 * pitch] = out[1 * pitch] = out[2 * pitch] = out[3 * pitch] = 0;
    }
    in++;
    out++;
}
}
