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
    // Variant 2: Indirect memory access via index array
    // Use an index lookup table to access destination locations non-sequentially
    static const int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Example permutation
    av_alias64 **dst_table = (av_alias64**)malloc(8 * sizeof(av_alias64*));
    if (!dst_table) return;

    for (int i = 0; i < 8; i++) {
        dst_table[i] = (av_alias64*)(dst + indices[i] * (stride / sizeof(uint16_t)));
    }

    for (y = 0; y < 8; y++) {
        dst_table[y][0].u64 = val;
        dst_table[y][1].u64 = val;
    }

    free(dst_table);
}
