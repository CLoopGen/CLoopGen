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
for (i = 0; i < width; i += 1) {
    uint8_t val_00 = src[(0) * src_stride + 1 * (0)];
    uint8_t val_11 = src[(1) * src_stride + 1 * (1)];
    uint8_t val_01 = src[(0) * src_stride + 1 * (1)];

    unsigned int avg = ((unsigned int)val_00 + (unsigned int)val_11) >> 1;

    dst[(0) * dst_stride + (0) * 3 + 0] = val_01;
    dst[(0) * dst_stride + (1) * 3 + 0] = val_01;
    dst[(1) * dst_stride + (1) * 3 + 0] = val_01;
    dst[(1) * dst_stride + (0) * 3 + 0] = val_01;

    dst[(0) * dst_stride + (0) * 3 + 1] = val_00;
    dst[(1) * dst_stride + (1) * 3 + 1] = val_11;
    dst[(0) * dst_stride + (1) * 3 + 1] = avg;
    dst[(1) * dst_stride + (0) * 3 + 1] = avg;

    dst[(1) * dst_stride + (1) * 3 + 2] = val_00;
    dst[(0) * dst_stride + (0) * 3 + 2] = val_00;
    dst[(0) * dst_stride + (1) * 3 + 2] = val_00;
    dst[(1) * dst_stride + (0) * 3 + 2] = val_00;

    src += 1 * 1;
    dst += 3;
}
}
