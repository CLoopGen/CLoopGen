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
    // Variant 2: Strided access with increasing stride multiples
    ptrdiff_t effective_stride = stride / sizeof(uint16_t);
    for (i = 0; i < 16; i++) {
        uint16_t *offset_src = src + (i * effective_stride);
        // Write to four non-consecutive 8-byte aligned locations with fixed offset pattern
        ((av_alias64*)(offset_src + 0 * effective_stride))->u64 = ((1ULL << (9 - 1)) * 281479271743489ULL);
        ((av_alias64*)(offset_src + 1 * effective_stride))->u64 = ((1ULL << (9 - 1)) * 281479271743489ULL);
        ((av_alias64*)(offset_src + 2 * effective_stride))->u64 = ((1ULL << (9 - 1)) * 281479271743489ULL);
        ((av_alias64*)(offset_src + 3 * effective_stride))->u64 = ((1ULL << (9 - 1)) * 281479271743489ULL);
    }
}
