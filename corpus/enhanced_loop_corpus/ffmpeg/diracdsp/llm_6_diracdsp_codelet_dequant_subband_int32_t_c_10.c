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
    int32_t c, *src_r = (int32_t *)src, *dst_r = (int32_t *)dst;
    int32_t temp_accum = 0;
    for (i = 0; i < tot_h; i++) {
        c = *src_r++;
        if (c < 0)
            c = -((-(unsigned int)c * qf + qs + temp_accum) >> 2);
        else if (c > 0)
            c = (((unsigned int)c * qf + qs + temp_accum) >> 2);
        temp_accum = c & 0xFF; // Introduce loop-carried dependency via temp_accum
        *dst_r++ = c;
    }
    src += tot_h << (sizeof(int32_t) >> 1);
    dst += stride;
}
}
