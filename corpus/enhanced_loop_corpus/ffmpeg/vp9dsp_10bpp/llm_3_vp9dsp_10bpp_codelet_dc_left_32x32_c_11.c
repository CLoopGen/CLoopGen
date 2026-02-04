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
extern uint16_t *dst;
extern uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *base_dst;
    ptrdiff_t offsets[8] = {0, 4, 8, 12, 16, 20, 24, 28};
    for (y = 0; y < 32; y++) {
        base_dst = dst;
        for (int i = 0; i < 8; i++) {
            ((av_alias64 *)(base_dst + offsets[i]))->u64 = dc;
        }
        dst += stride;
    }
}
