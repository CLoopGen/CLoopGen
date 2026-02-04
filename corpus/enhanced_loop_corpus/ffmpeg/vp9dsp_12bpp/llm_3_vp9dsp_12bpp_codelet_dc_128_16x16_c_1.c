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
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed and scattered write pattern
    uint16_t **dst_ptr = (uint16_t **)malloc(16 * sizeof(uint16_t*));
    if (!dst_ptr) return;
    for (int i = 0; i < 16; i++) {
        dst_ptr[i] = dst + i * stride;
    }
    for (y = 0; y < 16; y++) {
        uint16_t *base = dst_ptr[15 - y]; // Reverse order access
        ((av_alias64 *)(base + 12))->u64 = val; // High offset first
        ((av_alias64 *)(base + 8))->u64 = val;
        ((av_alias64 *)(base + 4))->u64 = val;
        ((av_alias64 *)(base + 0))->u64 = val; // End with low offset
    }
    free(dst_ptr);
}
