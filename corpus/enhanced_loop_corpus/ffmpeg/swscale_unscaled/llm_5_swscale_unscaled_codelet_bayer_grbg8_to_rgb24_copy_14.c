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
        uint8_t val_00 = src[(0) * src_stride + 1 * (0)];
        uint8_t val_11 = src[(1) * src_stride + 1 * (1)];
        uint8_t val_01 = src[(0) * src_stride + 1 * (1)];
        uint8_t val_10 = src[(1) * src_stride + 1 * (0)];

        unsigned int avg_val = (val_00 + val_11) >> 1;

        if (val_01 > 127) {
            dst[(0) * dst_stride + (0) * 3 + 2] = val_10;
            dst[(0) * dst_stride + (1) * 3 + 2] = val_10;
            dst[(1) * dst_stride + (1) * 3 + 2] = val_10;
            dst[(1) * dst_stride + (0) * 3 + 2] = val_10;
        }

        dst[(0) * dst_stride + (0) * 3 + 1] = val_00;
        dst[(1) * dst_stride + (1) * 3 + 1] = val_11;

        if (val_00 < val_11) {
            dst[(0) * dst_stride + (1) * 3 + 1] = avg_val;
            dst[(1) * dst_stride + (0) * 3 + 1] = avg_val;
        } else {
            dst[(0) * dst_stride + (1) * 3 + 1] = val_00;
            dst[(1) * dst_stride + (0) * 3 + 1] = val_11;
        }

        dst[(1) * dst_stride + (1) * 3 + 0] = dst[(0) * dst_stride + (0) * 3 + 0] = 
        dst[(0) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = val_01;

        src += 2;
        dst += 6;
    }
}
