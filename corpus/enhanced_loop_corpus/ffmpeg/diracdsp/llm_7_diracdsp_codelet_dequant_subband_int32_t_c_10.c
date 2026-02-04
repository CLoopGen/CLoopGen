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
    int32_t *src_r = (int32_t *)src, *dst_r = (int32_t *)dst;
    int32_t buffer[4] = {0}; // Local buffer to break direct dependencies
    for (i = 0; i < tot_h; i += 4) {
        // Unroll by 4 and eliminate per-iteration dependency
        for (int j = 0; j < 4 && (i + j) < tot_h; j++) {
            int32_t c = src_r[i + j];
            if (c < 0)
                buffer[j] = -((-(unsigned int)c * qf + qs) >> 2);
            else if (c > 0)
                buffer[j] = (((unsigned int)c * qf + qs) >> 2);
            else
                buffer[j] = 0;
        }
        for (int j = 0; j < 4 && (i + j) < tot_h; j++) {
            dst_r[i + j] = buffer[j]; // Write back without data flow between elements
        }
    }
    src += tot_h << (sizeof(int32_t) >> 1);
    dst += stride;
}
}
