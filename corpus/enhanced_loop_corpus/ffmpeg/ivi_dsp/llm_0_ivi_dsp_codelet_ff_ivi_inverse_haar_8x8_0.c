#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern int shift;
extern int sp1;
extern int sp2;
extern int sp3;
extern int sp4;
extern  int32_t *src;
extern int32_t *dst;
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
            shift = !(i & 4);
            sp1 = src[0] * (1 << shift);
            sp2 = src[8] * (1 << shift);
            sp3 = src[16] * (1 << shift);
            sp4 = src[24] * (1 << shift);
            {
                t1 = (sp1) * 2;
                t5 = (sp2) * 2;
                t0 = ((t1) - (t5)) >> 1;
                t1 = ((t1) + (t5)) >> 1;
                t5 = (t0);
                ;
                t0 = ((t1) - (sp3)) >> 1;
                t1 = ((t1) + (sp3)) >> 1;
                t3 = (t0);
                ;
                t0 = ((t5) - (sp4)) >> 1;
                t5 = ((t5) + (sp4)) >> 1;
                t7 = (t0);
                ;
                t0 = ((t1) - (src[32])) >> 1;
                t1 = ((t1) + (src[32])) >> 1;
                t2 = (t0);
                ;
                t0 = ((t3) - (src[40])) >> 1;
                t3 = ((t3) + (src[40])) >> 1;
                t4 = (t0);
                ;
                t0 = ((t5) - (src[48])) >> 1;
                t5 = ((t5) + (src[48])) >> 1;
                t6 = (t0);
                ;
                t0 = ((t7) - (src[56])) >> 1;
                t7 = ((t7) + (src[56])) >> 1;
                t8 = (t0);
                ;
                dst[0] = (t1);
                dst[8] = (t2);
                dst[16] = (t3);
                dst[24] = (t4);
                dst[32] = (t5);
                dst[40] = (t6);
                dst[48] = (t7);
                dst[56] = (t8);
            }
            ;
        } else
            dst[0] = dst[8] = dst[16] = dst[24] = dst[32] = dst[40] = dst[48] = dst[56] = 0;
        src++;
        dst++;
    }
}
