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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an explicit lookup table for non-sequential row access
    int indices[4] = {3, 1, 2, 0}; // Randomized order
    for (i = 0; i < 4; i++) {
        int idx = indices[i]; // Indirect access through index remapping
        uint64_t *row = (uint64_t*)(src + idx * stride);
        ((av_alias64*)(row + 0))->u64 = dc0splat;
        ((av_alias64*)(row + 1))->u64 = dc1splat;
    }
}
