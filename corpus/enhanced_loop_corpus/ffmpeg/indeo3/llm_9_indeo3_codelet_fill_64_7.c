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
    int32_t local_n = n >> 2;
    for (; local_n > 0; --local_n) {
        ((av_alias64 *)(dst))->u64 = pix;
        ((av_alias64 *)(dst + 8))->u64 = pix ^ 0xAAAAAAAA55555555ULL;
        ((av_alias64 *)(dst + 16))->u64 = pix ^ 0xCCCCCCCC33333333ULL;
        ((av_alias64 *)(dst + 24))->u64 = pix ^ 0xF0F0F0F00F0F0F0FULL;
        dst += row_offset * 4;
    }
    n -= (n >> 2) << 2;
    for (; n > 0; dst += row_offset, n--) {
        ((av_alias64 *)(dst))->u64 = pix;
    }
}
