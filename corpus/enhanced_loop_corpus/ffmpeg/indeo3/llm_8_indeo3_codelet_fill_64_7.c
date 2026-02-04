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
extern  uint64_t pix;
extern int32_t n;
extern int32_t row_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i;
    for (i = 0; i < n * 4; i += 4) {
        ((av_alias64 *)(dst + i))->u32[0] = (uint32_t)(pix & 0xFFFFFFFF);
        ((av_alias64 *)(dst + i))->u32[1] = (uint32_t)((pix >> 32) & 0xFFFFFFFF);
        ((av_alias64 *)(dst + i + 8))->u32[0] = (uint32_t)(pix & 0xFFFFFFFF);
        ((av_alias64 *)(dst + i + 8))->u32[1] = (uint32_t)((pix >> 32) & 0xFFFFFFFF);
        if (i + 16 >= n * 4) break;
    }
    dst += n * row_offset;
    n = 0;
}
