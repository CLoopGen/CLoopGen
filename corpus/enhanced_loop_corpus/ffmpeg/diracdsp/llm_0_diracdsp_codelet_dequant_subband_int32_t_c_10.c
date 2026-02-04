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
    int32_t c;
    for (y = 0; y < tot_v; y++) {
        int32_t *src_r = (int32_t *)src;
        int32_t *dst_r = (int32_t *)dst;
        i = 0;
        while (i < tot_h) {  // Introducing inner sequential unrolling by increasing nesting depth via manual unroll emulation
            c = *src_r++;
            if (c < 0)
                c = -((-(unsigned int)c * qf + qs) >> 2);
            else if (c > 0)
                c = (((unsigned int)c * qf + qs) >> 2);
            *dst_r++ = c;
            i++;
            if (i >= tot_h) break;

            c = *src_r++;
            if (c < 0)
                c = -((-(unsigned int)c * qf + qs) >> 2);
            else if (c > 0)
                c = (((unsigned int)c * qf + qs) >> 2);
            *dst_r++ = c;
            i++;
        }
        src += tot_h << (sizeof(int32_t) >> 1);
        dst += stride;
    }
}
