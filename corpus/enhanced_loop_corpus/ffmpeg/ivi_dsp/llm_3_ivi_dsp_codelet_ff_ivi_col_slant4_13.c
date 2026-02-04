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
// Use consecutive array access via local buffer to improve locality
int32_t local_in[16];
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        // Load 16 elements consecutively into local buffer for coherent access
        for (int j = 0; j < 16; j++) {
            local_in[j] = in[j];
        }
        t0 = (local_in[0]) - (local_in[8]);
        t1 = (local_in[0]) + (local_in[8]);
        t2 = (t0);
        ;
        t0 = (((local_in[4]) + (local_in[12]) * 2 + 2) >> 2) + (local_in[4]);
        t3 = (((local_in[4]) * 2 - (local_in[12]) + 2) >> 2) - (local_in[12]);
        t4 = (t0);
        ;
        t0 = (t1) - (t4);
        t1 = (t1) + (t4);
        t4 = (t0);
        ;
        t0 = (t2) - (t3);
        t2 = (t2) + (t3);
        t3 = (t0);
        ;
        out[0] = (((t1) + 1) >> 1);
        out[pitch] = (((t2) + 1) >> 1);
        out[row2] = (((t3) + 1) >> 1);
        out[row2 + pitch] = (((t4) + 1) >> 1);
    } else {
        out[0] = out[pitch] = out[row2] = out[row2 + pitch] = 0;
    }
    in += 16; // Advance input by block size
    out++;
}
}
