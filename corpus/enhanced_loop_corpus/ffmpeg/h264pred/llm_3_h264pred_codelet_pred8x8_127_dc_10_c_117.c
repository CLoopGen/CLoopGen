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
extern  uint64_t a;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an index lookup table to access memory in non-linear, indirect order
    uint64_t *base = (uint64_t*)src;
    int indices[16];
    // Generate a scrambled access pattern (e.g., bit-reversed or shuffled indices)
    for (int j = 0; j < 16; j++) {
        indices[j] = ((j & 1) << 3) | ((j & 2) << 1) | ((j & 4) >> 1) | ((j & 8) >> 3); // 4-bit reverse
    }
    for (i = 0; i < 16; i++) {
        int idx = indices[i];
        (((av_alias64 *)(base + idx))->u64 = (a));
    }
}
