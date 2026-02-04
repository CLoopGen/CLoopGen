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
for (i = 0; i < width; i += 4) {
    uint8_t val_00 = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l) >> 8;
    uint8_t val_01 = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l) >> 8;
    uint8_t val_10 = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l) >> 8;
    uint8_t val_11 = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l) >> 8;

    unsigned int avg_01_10 = (val_01 + val_10) >> 1;

    dst[(0) * dst_stride + (0) * 3 + 0] = val_11;
    dst[(0) * dst_stride + (1) * 3 + 0] = val_11;
    dst[(1) * dst_stride + (1) * 3 + 0] = val_11;
    dst[(1) * dst_stride + (0) * 3 + 0] = val_11;

    dst[(0) * dst_stride + (1) * 3 + 1] = val_01;

    dst[(0) * dst_stride + (0) * 3 + 1] = avg_01_10;
    dst[(1) * dst_stride + (1) * 3 + 1] = avg_01_10;

    dst[(1) * dst_stride + (0) * 3 + 1] = val_10;

    dst[(1) * dst_stride + (1) * 3 + 2] = val_00;
    dst[(0) * dst_stride + (0) * 3 + 2] = val_00;
    dst[(0) * dst_stride + (1) * 3 + 2] = val_00;
    dst[(1) * dst_stride + (0) * 3 + 2] = val_00;

    if (i + 2 < width) {
        const uint8_t* src_next = src + 2;
        uint8_t val_00_n = (((const union unaligned_16 *)(&(src_next[(0) * src_stride + 2 * (0)])))->l) >> 8;
        uint8_t val_01_n = (((const union unaligned_16 *)(&(src_next[(0) * src_stride + 2 * (1)])))->l) >> 8;
        uint8_t val_10_n = (((const union unaligned_16 *)(&(src_next[(1) * src_stride + 2 * (0)])))->l) >> 8;
        uint8_t val_11_n = (((const union unaligned_16 *)(&(src_next[(1) * src_stride + 2 * (1)])))->l) >> 8;

        unsigned int avg_01_10_n = (val_01_n + val_10_n) >> 1;

        dst[6 + (0) * dst_stride + (0) * 3 + 0] = val_11_n;
        dst[6 + (0) * dst_stride + (1) * 3 + 0] = val_11_n;
        dst[6 + (1) * dst_stride + (1) * 3 + 0] = val_11_n;
        dst[6 + (1) * dst_stride + (0) * 3 + 0] = val_11_n;

        dst[6 + (0) * dst_stride + (1) * 3 + 1] = val_01_n;

        dst[6 + (0) * dst_stride + (0) * 3 + 1] = avg_01_10_n;
        dst[6 + (1) * dst_stride + (1) * 3 + 1] = avg_01_10_n;

        dst[6 + (1) * dst_stride + (0) * 3 + 1] = val_10_n;

        dst[6 + (1) * dst_stride + (1) * 3 + 2] = val_00_n;
        dst[6 + (0) * dst_stride + (0) * 3 + 2] = val_00_n;
        dst[6 + (0) * dst_stride + (1) * 3 + 2] = val_00_n;
        dst[6 + (1) * dst_stride + (0) * 3 + 2] = val_00_n;
    }

    src += 4 * 2;
    dst += 12;
}
}
