#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i += 2) {
        uint16_t val_00 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
        uint16_t val_01 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
        uint16_t val_10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
        uint16_t val_11 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;

        unsigned int avg_mid = (val_01 + val_10) >> 1;

        dst[(0) * dst_stride + (0) * 3 + 0] = val_11 >> 8;
        dst[(0) * dst_stride + (1) * 3 + 0] = val_11 >> 8;
        dst[(1) * dst_stride + (1) * 3 + 0] = val_11 >> 8;
        dst[(1) * dst_stride + (0) * 3 + 0] = val_11 >> 8;

        dst[(0) * dst_stride + (1) * 3 + 1] = val_01 >> 8;

        if (i % 4 == 0) {
            dst[(0) * dst_stride + (0) * 3 + 1] = avg_mid >> 8;
            dst[(1) * dst_stride + (1) * 3 + 1] = avg_mid >> 8;
        } else {
            dst[(0) * dst_stride + (0) * 3 + 1] = val_00 >> 8;
            dst[(1) * dst_stride + (1) * 3 + 1] = val_11 >> 8;
        }

        dst[(1) * dst_stride + (0) * 3 + 1] = val_10 >> 8;

        dst[(1) * dst_stride + (1) * 3 + 2] = val_00 >> 8;
        dst[(0) * dst_stride + (0) * 3 + 2] = val_00 >> 8;
        dst[(0) * dst_stride + (1) * 3 + 2] = val_00 >> 8;
        dst[(1) * dst_stride + (0) * 3 + 2] = val_00 >> 8;

        src += 2 * 2;
        dst += 6;
    }
}
