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
extern uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an explicit index array to simulate non-sequential, indirect addressing
    static const int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Logical row mapping
    uint16_t *base_dst = dst;
    for (y = 0; y < 8; y++) {
        int offset = indices[y] * (stride / sizeof(uint16_t));
        ((av_alias64 *)(base_dst + offset + 0))->u64 = dc;
        ((av_alias64 *)(base_dst + offset + 4))->u64 = dc;
        base_dst += stride;
    }
}
