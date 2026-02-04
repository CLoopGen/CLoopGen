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
    int16_t c, *src_r = (int16_t *)src, *dst_r = (int16_t *)dst;
    for (i = 0; i < tot_h; i++) {
        c = *src_r++;
        if (c == 0) {
            *dst_r++ = 0;
            continue;
        }
        unsigned int abs_c = (c < 0) ? -(unsigned int)c : (unsigned int)c;
        int sign = (c < 0) ? -1 : 1;
        c = sign * ((abs_c * qf + qs) >> 2);
        *dst_r++ = c;
    }
    src += tot_h << (sizeof(int16_t) >> 1);
    dst += stride;
}
}
