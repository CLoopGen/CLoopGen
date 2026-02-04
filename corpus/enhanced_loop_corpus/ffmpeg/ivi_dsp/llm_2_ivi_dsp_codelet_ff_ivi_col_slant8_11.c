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
extern int row4;
extern int row8;
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



void loop() {
    for (i = 0; i < 8; i++) {
        if (flags[i]) {
            int32_t *in_offset = &in[i * 8]; // Strided access with step of 8 elements
            int16_t *out_offset = &out[i];

            t0 = (in_offset[24]) + (((in_offset[8]) * 4 - (in_offset[24]) + 4) >> 3);
            t5 = (in_offset[8]) + ((-(in_offset[8]) - (in_offset[24]) * 4 + 4) >> 3);
            t4 = (t0);
            ;
            t0 = (in_offset[0]) - (t5);
            t1 = (in_offset[0]) + (t5);
            t5 = (t0);
            ;
            t0 = (in_offset[32]) - (in_offset[40]);
            t2 = (in_offset[32]) + (in_offset[40]);
            t6 = (t0);
            ;
            t0 = (in_offset[56]) - (in_offset[48]);
            t7 = (in_offset[56]) + (in_offset[48]);
            t3 = (t0);
            ;
            t0 = (t4) - (in_offset[16]);
            t4 = (t4) + (in_offset[16]);
            t8 = (t0);
            ;
            t0 = (t1) - (t2);
            t1 = (t1) + (t2);
            t2 = (t0);
            ;
            t0 = (((t4) + (t3) * 2 + 2) >> 2) + (t4);
            t3 = (((t4) * 2 - (t3) + 2) >> 2) - (t3);
            t4 = (t0);
            ;
            t0 = (t5) - (t6);
            t5 = (t5) + (t6);
            t6 = (t0);
            ;
            t0 = (((t8) + (t7) * 2 + 2) >> 2) + (t8);
            t7 = (((t8) * 2 - (t7) + 2) >> 2) - (t7);
            t8 = (t0);
            ;
            t0 = (t1) - (t4);
            t1 = (t1) + (t4);
            t4 = (t0);
            ;
            t0 = (t2) - (t3);
            t2 = (t2) + (t3);
            t3 = (t0);
            ;
            t0 = (t5) - (t8);
            t5 = (t5) + (t8);
            t8 = (t0);
            ;
            t0 = (t6) - (t7);
            t6 = (t6) + (t7);
            t7 = (t0);
            ;

            out_offset[0]               = (((t1) + 1) >> 1);
            out_offset[pitch]           = (((t2) + 1) >> 1);
            out_offset[row2]            = (((t3) + 1) >> 1);
            out_offset[row2 + pitch]    = (((t4) + 1) >> 1);
            out_offset[row4]            = (((t5) + 1) >> 1);
            out_offset[row4 + pitch]    = (((t6) + 1) >> 1);
            out_offset[row4 + row2]     = (((t7) + 1) >> 1);
            out_offset[row8 - pitch]    = (((t8) + 1) >> 1);
        } else {
            int16_t *out_offset = &out[i];
            out_offset[0] = out_offset[pitch] = out_offset[row2] = out_offset[row2 + pitch] =
            out_offset[row4] = out_offset[row4 + pitch] = out_offset[row4 + row2] = out_offset[row8 - pitch] = 0;
        }
    }
}
