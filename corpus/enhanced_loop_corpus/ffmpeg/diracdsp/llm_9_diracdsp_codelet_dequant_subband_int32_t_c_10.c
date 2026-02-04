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
    int32_t c;
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    for (int block = 0; block < 2 && y + block < tot_v; ++block) {
        int32_t *src_r = (int32_t *)(src_local);
        int32_t *dst_r = (int32_t *)(dst_local);
        for (i = 0; i < tot_h; i++) {
            c = *src_r++;
            c = (c == 0) ? 0 : (c < 0) ? 
                -(((-(unsigned int)c * qf + qs) >> 1) + 1) >> 1 :
                (((((unsigned int)c * qf + qs) >> 1) + 1) >> 1);
            *dst_r++ = c;
        }
        src_local += tot_h << (sizeof(int32_t) >> 1);
        dst_local += stride;
    }
    src = src_local;
    dst = dst_local;
}
}
