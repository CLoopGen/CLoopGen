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
            for (int j = 0; j < 1; j++) {  // Introduce inner loop with fixed iteration to increase nesting depth
                t0 = (src[0]) - (src[8]);
                t1 = (src[0]) + (src[8]);
                t2 = (t0);
                ;
                t0 = (((src[4]) + (src[12]) * 2 + 2) >> 2) + (src[4]);
                t3 = (((src[4]) * 2 - (src[12]) + 2) >> 2) - (src[12]);
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
                dst[0] = (t1);
                dst[4] = (t2);
                dst[8] = (t3);
                dst[12] = (t4);
            }
        } else {
            dst[0] = dst[4] = dst[8] = dst[12] = 0;
        }
        src++;
        dst++;
    }
}
