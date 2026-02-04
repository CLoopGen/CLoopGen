#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 16) {
            dst[j + 0] = src[j + 0];
            dst[j + 1] = src[j + 1];
            dst[j + 2] = src[j + 2];
            dst[j + 3] = src[j + 3];
            dst[j + 4] = src[j + 4];
            dst[j + 5] = src[j + 5];
            dst[j + 6] = src[j + 6];
            dst[j + 7] = src[j + 7];
            dst[j + 8] = src[j + 8];
            dst[j + 9] = src[j + 9];
            dst[j + 10] = src[j + 10];
            dst[j + 11] = src[j + 11];
            dst[j + 12] = src[j + 12];
            dst[j + 13] = src[j + 13];
            dst[j + 14] = src[j + 14];
            dst[j + 15] = src[j + 15];
        }
        dst += stride_dst;
        src += stride_src;
    }
}
