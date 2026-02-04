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
        int32_t *s = &src[0]; // Base pointer for consecutive access with offset indexing
        {
            t0 = (s[24]) + (((s[8]) * 4 - (s[24]) + 4) >> 3);
            t5 = (s[8]) + ((-(s[8]) - (s[24]) * 4 + 4) >> 3);
            t4 = (t0);
            ;
            t0 = (s[0]) - (t5);
            t1 = (s[0]) + (t5);
            t5 = (t0);
            ;
            t0 = (s[32]) - (s[40]);
            t2 = (s[32]) + (s[40]);
            t6 = (t0);
            ;
            t0 = (s[56]) - (s[48]);
            t7 = (s[56]) + (s[48]);
            t3 = (t0);
            ;
            t0 = (t4) - (s[16]);
            t4 = (t4) + (s[16]);
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
            int32_t *d = &dst[0];
            d[0] = (t1);
            d[8] = (t2);
            d[16] = (t3);
            d[24] = (t4);
            d[32] = (t5);
            d[40] = (t6);
            d[48] = (t7);
            d[56] = (t8);
        }
        ;
    } else {
        int32_t *d = &dst[0];
        d[0] = d[8] = d[16] = d[24] = d[32] = d[40] = d[48] = d[56] = 0;
    }
    src += 1;
    dst += 1;
}
}
