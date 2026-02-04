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
    for (i = 0; i < 32; i += 2) {
        uint64_t base_val = (1 << 13) * 281479271743489ULL;
        uint64_t offset1 = base_val + (i * 1000ULL);
        uint64_t offset2 = base_val ^ (i * 500ULL);
        (((av_alias64 *)(src + 0))->u64 = offset1);
        (((av_alias64 *)(src + 4))->u64 = offset2);
        (((av_alias64 *)(src + 8))->u64 = offset1);
        (((av_alias64 *)(src + 12))->u64 = offset2);
        src += stride;
        if (i % 4 == 0) {
            (((av_alias64 *)(src + 0))->u64 = (offset1 ^ offset2));
            src += stride;
        }
    }
}
