#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 2) {
    uint8_t temp_val_1 = src[(0) * src_stride + 1 * (0)];
    uint8_t temp_val_2 = src[(0) * src_stride + 1 * (1)];
    uint8_t temp_val_3 = src[(1) * src_stride + 1 * (0)];
    uint8_t temp_val_4 = src[(1) * src_stride + 1 * (1)];

    if ((temp_val_2 + temp_val_3) > 128) {
        dst[(0) * dst_stride + (0) * 3 + 2] = dst[(0) * dst_stride + (1) * 3 + 2] = 
        dst[(1) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (0) * 3 + 2] = temp_val_4;
        dst[(0) * dst_stride + (1) * 3 + 1] = temp_val_2;
        dst[(0) * dst_stride + (0) * 3 + 1] = dst[(1) * dst_stride + (1) * 3 + 1] = 
            ((unsigned int)temp_val_2 + (unsigned int)temp_val_3) >> 1;
        dst[(1) * dst_stride + (0) * 3 + 1] = temp_val_3;
        dst[(1) * dst_stride + (1) * 3 + 0] = dst[(0) * dst_stride + (0) * 3 + 0] = 
        dst[(0) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = temp_val_1;
    } else {
        dst[(0) * dst_stride + (0) * 3 + 2] = temp_val_4;
        dst[(1) * dst_stride + (1) * 3 + 2] = temp_val_4;
        dst[(0) * dst_stride + (1) * 3 + 1] = temp_val_2;
        dst[(1) * dst_stride + (0) * 3 + 1] = temp_val_3;
        dst[(0) * dst_stride + (0) * 3 + 0] = temp_val_1;
    }

    src += 2 * 1;
    dst += 6;
}
}
