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
    // Variant 2: Strided access with transposed write pattern across iterations
    uint16_t *temp_src = src;
    for (i = 0; i < 16; i++) {
        // Interleave stores to different offsets over iterations
        ((av_alias64 *)(temp_src + 0))->u64 = (((1 << (9 - 1)) - 1) * 281479271743489ULL);
        ((av_alias64 *)(temp_src + stride / sizeof(uint16_t) * 4))->u64 = (((1 << (9 - 1)) - 1) * 281479271743489ULL);
        ((av_alias64 *)(temp_src + stride / sizeof(uint16_t) * 8))->u64 = (((1 << (9 - 1)) - 1) * 281479271743489ULL);
        ((av_alias64 *)(temp_src + stride / sizeof(uint16_t) * 12))->u64 = (((1 << (9 - 1)) - 1) * 281479271743489ULL);

        temp_src += stride / sizeof(uint16_t);
    }
}
