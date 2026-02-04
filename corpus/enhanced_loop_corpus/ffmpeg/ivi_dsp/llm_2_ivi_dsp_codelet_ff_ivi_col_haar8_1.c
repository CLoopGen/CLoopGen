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
        int32_t *in_ptr = in;
        ptrdiff_t offsets[] = {0, 8, 16, 24, 32, 40, 48, 56};
        t1 = (in_ptr[offsets[0]]) * 2;
        t5 = (in_ptr[offsets[1]]) * 2;
        t0 = ((t1) - (t5)) >> 1;
        t1 = ((t1) + (t5)) >> 1;
        t5 = (t0);
        t0 = ((t1) - (in_ptr[offsets[2]])) >> 1;
        t1 = ((t1) + (in_ptr[offsets[2]])) >> 1;
        t3 = (t0);
        t0 = ((t5) - (in_ptr[offsets[3]])) >> 1;
        t5 = ((t5) + (in_ptr[offsets[3]])) >> 1;
        t7 = (t0);
        t0 = ((t1) - (in_ptr[offsets[4]])) >> 1;
        t1 = ((t1) + (in_ptr[offsets[4]])) >> 1;
        t2 = (t0);
        t0 = ((t3) - (in_ptr[offsets[5]])) >> 1;
        t3 = ((t3) + (in_ptr[offsets[5]])) >> 1;
        t4 = (t0);
        t0 = ((t5) - (in_ptr[offsets[6]])) >> 1;
        t5 = ((t5) + (in_ptr[offsets[6]])) >> 1;
        t6 = (t0);
        t0 = ((t7) - (in_ptr[offsets[7]])) >> 1;
        t7 = ((t7) + (in_ptr[offsets[7]])) >> 1;
        t8 = (t0);
        out[0 * pitch] = (int16_t)(t1);
        out[1 * pitch] = (int16_t)(t2);
        out[2 * pitch] = (int16_t)(t3);
        out[3 * pitch] = (int16_t)(t4);
        out[4 * pitch] = (int16_t)(t5);
        out[5 * pitch] = (int16_t)(t6);
        out[6 * pitch] = (int16_t)(t7);
        out[7 * pitch] = (int16_t)(t8);
    } else {
        out[0 * pitch] = out[1 * pitch] = out[2 * pitch] = out[3 * pitch] = 
        out[4 * pitch] = out[5 * pitch] = out[6 * pitch] = out[7 * pitch] = 0;
    }
    in++;
    out++;
}
}
