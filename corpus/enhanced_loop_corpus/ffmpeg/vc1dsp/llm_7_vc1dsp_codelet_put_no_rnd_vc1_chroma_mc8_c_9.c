#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_local = dst;
    uint8_t *src_local = src;
    int i_local = 0;
    for (i = 0; i < h; i++) {
        dst_local[0] = ((A * src_local[0] + B * src_local[1] + C * src_local[stride] + D * src_local[stride + 1] + 32 - 4) >> 6);
        dst_local[1] = ((A * src_local[1] + B * src_local[2] + C * src_local[stride + 1] + D * src_local[stride + 2] + 32 - 4) >> 6);
        dst_local[2] = ((A * src_local[2] + B * src_local[3] + C * src_local[stride + 2] + D * src_local[stride + 3] + 32 - 4) >> 6);
        dst_local[3] = ((A * src_local[3] + B * src_local[4] + C * src_local[stride + 3] + D * src_local[stride + 4] + 32 - 4) >> 6);
        dst_local[4] = ((A * src_local[4] + B * src_local[5] + C * src_local[stride + 4] + D * src_local[stride + 5] + 32 - 4) >> 6);
        dst_local[5] = ((A * src_local[5] + B * src_local[6] + C * src_local[stride + 5] + D * src_local[stride + 6] + 32 - 4) >> 6);
        dst_local[6] = ((A * src_local[6] + B * src_local[7] + C * src_local[stride + 6] + D * src_local[stride + 7] + 32 - 4) >> 6);
        dst_local[7] = ((A * src_local[7] + B * src_local[8] + C * src_local[stride + 7] + D * src_local[stride + 8] + 32 - 4) >> 6);

        if (i_local > 0) {
            dst_local[-stride + 0] ^= dst_local[0]; 
        }

        dst_local += stride;
        src_local += stride;
        i_local++;
    }
    dst = dst_local;
    src = src_local;
    i = i_local;
}
