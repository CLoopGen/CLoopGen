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
    uint64_t prev_val = 0;
    for (i = 0; i < 16; i++) {
        uint64_t computed_val = ((((1 << (10 - 1)) + 1) * 281479271743489ULL)) ^ prev_val;
        (((av_alias64 *)(src + 0))->u64 = computed_val);
        (((av_alias64 *)(src + 4))->u64 = computed_val);
        (((av_alias64 *)(src + 8))->u64 = computed_val);
        (((av_alias64 *)(src + 12))->u64 = computed_val);

        prev_val = computed_val;
        src += stride;
    }
}
