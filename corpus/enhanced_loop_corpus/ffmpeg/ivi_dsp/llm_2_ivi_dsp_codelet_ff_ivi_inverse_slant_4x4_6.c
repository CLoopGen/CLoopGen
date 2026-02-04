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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    if (flags[i]) {
        {
            int idx = i * 16; // Strided access with base offset
            t0 = (src[idx + 0]) - (src[idx + 8]);
            t1 = (src[idx + 0]) + (src[idx + 8]);
            t2 = (t0);
            ;
            t0 = (((src[idx + 4]) + (src[idx + 12]) * 2 + 2) >> 2) + (src[idx + 4]);
            t3 = (((src[idx + 4]) * 2 - (src[idx + 12]) + 2) >> 2) - (src[idx + 12]);
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
            dst[idx + 0] = (t1);
            dst[idx + 4] = (t2);
            dst[idx + 8] = (t3);
            dst[idx + 12] = (t4);
        }
        ;
    } else {
        int idx = i * 16;
        dst[idx + 0] = dst[idx + 4] = dst[idx + 8] = dst[idx + 12] = 0;
    }
}
}
