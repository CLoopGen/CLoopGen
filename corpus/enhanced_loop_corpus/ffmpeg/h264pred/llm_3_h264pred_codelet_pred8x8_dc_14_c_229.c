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
    // Variant 2: Indirect memory access via an index array (simulating irregular/indirect access pattern)
    int indices[4] = {0, 2, 1, 3}; // Example permutation of row indices
    for (i = 0; i < 4; i++) {
        int idx = indices[i]; // Use indirection to access rows
        uint16_t *ptr = src + idx * stride;
        ((av_alias64 *)(((uint64_t *)ptr) + 0))->u64 = dc0splat;
        ((av_alias64 *)(((uint64_t *)ptr) + 1))->u64 = dc1splat;
    }
}
