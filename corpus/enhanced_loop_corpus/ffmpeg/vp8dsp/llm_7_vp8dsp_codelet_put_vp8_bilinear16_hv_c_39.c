#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_local = dst;
    ptrdiff_t dstride_local = dstride;
    int h_local = h;
    int c_local = c;
    int d_local = d;
    uint8_t *tmp_local = tmp;
    for (y = 0; y < h_local; y++) {
        for (x = 0; x < 16; x += 2) {
            dst_local[x] = (c_local * tmp_local[x] + d_local * tmp_local[x + 16] + 4) >> 3;
            if (x + 1 < 16) {
                dst_local[x + 1] = (c_local * tmp_local[x + 1] + d_local * tmp_local[x + 17] + 4) >> 3;
            }
        }
        dst_local += dstride_local;
        tmp_local += 16;
    }
}
