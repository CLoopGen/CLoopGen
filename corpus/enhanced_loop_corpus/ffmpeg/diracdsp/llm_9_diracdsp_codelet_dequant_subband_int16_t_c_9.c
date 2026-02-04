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
for (y = 0; y < tot_v; y += 2) {
    uint8_t *src_curr = src;
    uint8_t *dst_curr = dst;
    for (int row = 0; row < 2 && y + row < tot_v; row++) {
        int16_t c, *src_r = (int16_t *)src_curr, *dst_r = (int16_t *)dst_curr;
        for (i = 0; i < tot_h; i++) {
            unsigned int abs_c = (unsigned int)(c = *src_r++);
            int sign = (c > 0) - (c < 0);
            c = sign * ((abs_c * qf + qs) >> 2);
            *dst_r++ = c;
        }
        src_curr += tot_h << (sizeof(int16_t) >> 1);
        dst_curr += stride;
    }
    src += 2 * (tot_h << (sizeof(int16_t) >> 1));
    dst += 2 * stride;
}
}
