#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern  int qf;
extern  int qs;
extern int tot_v;
extern int tot_h;
extern int i;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < tot_v; y++) {
    int16_t *src_r = (int16_t *)src, *dst_r = (int16_t *)dst;
    // Eliminate intra-loop dependencies: make each iteration completely independent
    // Unroll by 2 and remove any sequential dependencies between iterations
    for (i = 0; i < tot_h - 1; i += 2) {
        int16_t c1 = src_r[i], c2 = src_r[i+1];
        int16_t r1, r2;

        // Process both elements independently (parallelizable)
        if (c1 < 0)
            r1 = -((-(unsigned int)c1 * qf + qs) >> 2);
        else if (c1 > 0)
            r1 = (((unsigned int)c1 * qf + qs) >> 2);
        else
            r1 = 0;

        if (c2 < 0)
            r2 = -((-(unsigned int)c2 * qf + qs) >> 2);
        else if (c2 > 0)
            r2 = (((unsigned int)c2 * qf + qs) >> 2);
        else
            r2 = 0;

        dst_r[i] = r1;
        dst_r[i+1] = r2;
    }
    // Handle remaining element if tot_h is odd
    if (i < tot_h) {
        int16_t c = src_r[i];
        if (c < 0)
            c = -((-(unsigned int)c * qf + qs) >> 2);
        else if (c > 0)
            c = (((unsigned int)c * qf + qs) >> 2);
        else
            c = 0;
        dst_r[i] = c;
    }
    src += tot_h << (sizeof(int16_t) >> 1);
    dst += stride;
}
}
