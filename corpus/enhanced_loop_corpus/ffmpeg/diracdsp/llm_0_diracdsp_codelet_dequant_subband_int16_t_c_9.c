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
    int16_t c;
    int i, j;
    int16_t *src_r = (int16_t *)src;
    int16_t *dst_r = (int16_t *)dst;
    for (i = 0; i < tot_h; i++) {
        c = *src_r++;
        if (c < 0)
            c = -((-(unsigned int)c * qf + qs) >> 2);
        else if (c > 0)
            c = (((unsigned int)c * qf + qs) >> 2);
        *dst_r++ = c;
    }
    src += tot_h << (sizeof(int16_t) >> 1);
    dst += stride;
}
}
