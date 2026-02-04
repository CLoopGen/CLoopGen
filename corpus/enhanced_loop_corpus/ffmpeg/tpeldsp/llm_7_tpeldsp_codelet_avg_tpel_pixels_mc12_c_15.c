#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    int offset;
    for (i = 0; i < height; i++) {
        offset = i * stride;
        for (j = 0; j < width; j++) {
            int val_src_j      = local_src[offset + j];
            int val_src_jp1    = (j + 1 < width) ? local_src[offset + j + 1] : val_src_j;
            int val_src_s_j    = local_src[offset + j + stride];
            int val_src_s_jp1  = (j + 1 < width) ? local_src[offset + j + stride + 1] : val_src_s_j;
            int computed = ((3 * val_src_j + 2 * val_src_jp1 + 
                            4 * val_src_s_j + 3 * val_src_s_jp1 + 6) * 2731) >> 15;
            local_dst[offset + j] = (local_dst[offset + j] + computed + 1) >> 1;
        }
    }
}
