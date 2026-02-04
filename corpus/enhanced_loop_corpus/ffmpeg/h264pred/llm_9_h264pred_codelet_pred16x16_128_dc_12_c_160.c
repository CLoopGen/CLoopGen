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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const uint64_t base_val = 281479271743489ULL;
    const uint64_t shift_val = (1 << (12 - 1));
    const uint64_t scaled_val = (shift_val + 0) * base_val;

    for (i = 0; i < 8; i++) {
        av_alias64 *a = (av_alias64*)(src + 0);
        av_alias64 *b = (av_alias64*)(src + 8);
        a->u64 = scaled_val;
        b->u64 = scaled_val;
        src += stride;
    }
}
