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
    t0 = ((t1) - (in[32])) >> 1;
    t1 = ((t1) + (in[32])) >> 1;
    t2 = (t0);
    t0 = ((t3) - (in[40])) >> 1;
    t3 = ((t3) + (in[40])) >> 1;
    t4 = (t0);
    t0 = ((t5) - (in[48])) >> 1;
    t5 = ((t5) + (in[48])) >> 1;
    t6 = (t0);
    t0 = ((t7) - (in[56])) >> 1;
    t7 = ((t7) + (in[56])) >> 1;
    t8 = (t0);

    out[0 * pitch] = flags[i] ? (t1) : 0;
    out[1 * pitch] = flags[i] ? (t2) : 0;
    out[2 * pitch] = flags[i] ? (t3) : 0;
    out[3 * pitch] = flags[i] ? (t4) : 0;
    out[4 * pitch] = flags[i] ? (t5) : 0;
    out[5 * pitch] = flags[i] ? (t6) : 0;
    out[6 * pitch] = flags[i] ? (t7) : 0;
    out[7 * pitch] = flags[i] ? (t8) : 0;

    in++;
    out++;
}
}
