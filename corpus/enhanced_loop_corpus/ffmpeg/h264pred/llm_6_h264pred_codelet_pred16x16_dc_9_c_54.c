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

extern ptrdiff_t stride;
extern int i;
extern uint16_t *src;
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp1, temp2, temp3, temp4;
    for (i = 0; i < 16; i++) {
        temp1 = dcsplat ^ i;
        temp2 = dcsplat ^ (i + 1);
        temp3 = dcsplat ^ (i + 2);
        temp4 = dcsplat ^ (i + 3);
        (((av_alias64 *)(src + 0))->u64 = temp1);
        (((av_alias64 *)(src + 4))->u64 = temp2);
        (((av_alias64 *)(src + 8))->u64 = temp3);
        (((av_alias64 *)(src + 12))->u64 = temp4);
        src += stride;
    }
}
