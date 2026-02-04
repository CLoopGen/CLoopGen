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
    // Use an array of indices to perform non-sequential, indirect addressing.
    // This simulates irregular or gather-style access patterns.
    static const int indices[8] = {0, 2, 1, 3, 7, 5, 6, 4}; // Arbitrary permutation
    for (i = 0; i < 8; i++) {
        int idx = indices[i]; // Indirect access through index mapping
        uint64_t *ptr = (uint64_t*)(src + idx * stride);
        ((av_alias64*)(ptr + 0))->u64 = a;
        ((av_alias64*)(ptr + 1))->u64 = a;
    }
}
