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
        int32_t temp_loads[8];
        for (int j = 0; j < 8; j++) {
            temp_loads[j] = in[j * 8];
        }

        t1 = (temp_loads[0]) * 2;
        t5 = (temp_loads[1]) * 2;
        t0 = ((t1) - (t5)) >> 1;
        t1 = ((t1) + (t5)) >> 1;
        t5 = t0;

        t0 = ((t1) - (temp_loads[2])) >> 1;
        t1 = ((t1) + (temp_loads[2])) >> 1;
        t3 = t0;

        t0 = ((t5) - (temp_loads[3])) >> 1;
        t5 = ((t5) + (temp_loads[3])) >> 1;
        t7 = t0;

        t0 = ((t1) - (temp_loads[4])) >> 1;
        t1 = ((t1) + (temp_loads[4])) >> 1;
        t2 = t0;

        t0 = ((t3) - (temp_loads[5])) >> 1;
        t3 = ((t3) + (temp_loads[5])) >> 1;
        t4 = t0;

        t0 = ((t5) - (temp_loads[6])) >> 1;
        t5 = ((t5) + (temp_loads[6])) >> 1;
        t6 = t0;

        t0 = ((t7) - (temp_loads[7])) >> 1;
        t7 = ((t7) + (temp_loads[7])) >> 1;
        t8 = t0;

        out[0 * pitch] = t1;
        out[1 * pitch] = t2;
        out[2 * pitch] = t3;
        out[3 * pitch] = t4;
        out[4 * pitch] = t5;
        out[5 * pitch] = t6;
        out[6 * pitch] = t7;
        out[7 * pitch] = t8;
    } else {
        int16_t val = 0;
        out[0 * pitch] = val;
        out[1 * pitch] = val;
        out[2 * pitch] = val;
        out[3 * pitch] = val;
        out[4 * pitch] = val;
        out[5 * pitch] = val;
        out[6 * pitch] = val;
        out[7 * pitch] = val;
    }
    in++;
    out++;
}
}
