#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
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
        t0 = (src[24]) + (((src[8]) * 4 - (src[24]) + 4) >> 3);
        t4 = t0;

        t5 = (src[8]) + ((-(src[8]) - (src[24]) * 4 + 4) >> 3);
        t0 = (src[0]) - t5;
        t1 = (src[0]) + t5;
        t5 = t0;

        t0 = (src[32]) - (src[40]);
        t2 = (src[32]) + (src[40]);
        t6 = t0;

        t0 = (src[56]) - (src[48]);
        t7 = (src[56]) + (src[48]);
        t3 = t0;

        t0 = t4 - (src[16]);
        t8 = t0;
        t4 = t4 + (src[16]);

        t0 = t1 - t2;
        t2 = t0;
        t1 = t1 + t2;

        t0 = (((t4 + t3 * 2 + 2) >> 2) + t4);
        t3 = (((t4 * 2 - t3 + 2) >> 2) - t3);
        t4 = t0;

        t0 = t5 - t6;
        t6 = t0;
        t5 = t5 + t6;

        t0 = (((t8 + t7 * 2 + 2) >> 2) + t8);
        t7 = (((t8 * 2 - t7 + 2) >> 2) - t7);
        t8 = t0;

        t0 = t1 - t4;
        t4 = t0;
        t1 = t1 + t4;

        t0 = t2 - t3;
        t3 = t0;
        t2 = t2 + t3;

        t0 = t5 - t8;
        t8 = t0;
        t5 = t5 + t8;

        t0 = t6 - t7;
        t7 = t0;
        t6 = t6 + t7;

        dst[0] = t1;
        dst[8] = t2;
        dst[16] = t3;
        dst[24] = t4;
        dst[32] = t5;
        dst[40] = t6;
        dst[48] = t7;
        dst[56] = t8;
    } else {
        dst[0] = 0;
        dst[8] = 0;
        dst[16] = 0;
        dst[24] = 0;
        dst[32] = 0;
        dst[40] = 0;
        dst[48] = 0;
        dst[56] = 0;
    }
    src += 1;
    dst += 1;
}
}
