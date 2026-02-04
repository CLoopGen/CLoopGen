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
    // Variant 2: Strided access with increasing offset steps (simulating non-unit stride over larger blocks)
    ptrdiff_t effective_stride = stride * 2; // Use a larger effective stride
    uint16_t *ptr = src;
    for (i = 0; i < 16; i++) {
        // Access every other block, creating a wider strided pattern across memory
        ((av_alias64 *)(ptr + 0))->u64 = ((((1 << (12 - 1)) - 1) * 281479271743489ULL));
        ((av_alias64 *)(ptr + 8))->u64 = ((((1 << (12 - 1)) - 1) * 281479271743489ULL));
        ((av_alias64 *)(ptr + 16))->u64 = ((((1 << (12 - 1)) - 1) * 281479271743489ULL));
        ((av_alias64 *)(ptr + 24))->u64 = ((((1 << (12 - 1)) - 1) * 281479271743489ULL));
        ptr += effective_stride;
    }
}
