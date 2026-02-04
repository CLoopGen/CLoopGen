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
    for (i = 0; i < 16; i++) {
        (((av_alias64 *)(src + 0))->u64 = (dcsplat));
        if (i < 8) {
            (((av_alias64 *)(src + 4))->u64 = (dcsplat));
            (((av_alias64 *)(src + 12))->u64 = (dcsplat));
        }
        (((av_alias64 *)(src + 8))->u64 = (dcsplat));
        if (i >= 4 && i < 12) {
            (((av_alias64 *)(src + 12))->u64 = (dcsplat));
        }
        src += stride;
    }
}
