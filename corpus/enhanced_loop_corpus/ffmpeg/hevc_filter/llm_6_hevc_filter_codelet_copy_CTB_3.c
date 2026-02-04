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
        uint64_t temp1 = ((const av_alias64 *)(src + j))->u64;
        uint64_t temp2 = ((const av_alias64 *)((char *)(src + j) + 8))->u64;
        ((av_alias64 *)(dst + j))->u64 = temp1;
        ((av_alias64 *)((char *)(dst + j) + 8))->u64 = temp2;
    }
    dst += stride_dst;
    src += stride_src;
}
}
