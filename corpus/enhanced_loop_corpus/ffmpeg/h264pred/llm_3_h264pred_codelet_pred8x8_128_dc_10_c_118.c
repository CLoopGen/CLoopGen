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
    // Use an lookup table to access src locations indirectly
    static const int indices[8] = {7, 0, 5, 2, 6, 1, 4, 3}; // arbitrary permutation
    uint64_t *ptr;
    for (i = 0; i < 8; i++) {
        ptr = (uint64_t*)(src + indices[i] * stride);
        (((av_alias64 *)(ptr + 0))->u64 = (a));
        (((av_alias64 *)(ptr + 1))->u64 = (a));
    }
}
