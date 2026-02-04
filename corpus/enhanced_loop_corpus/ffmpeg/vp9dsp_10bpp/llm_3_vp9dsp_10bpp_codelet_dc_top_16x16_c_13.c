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
    // Use an indirection table to access rows with variable offsets
    static const int indices[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    uint16_t **rows = (uint16_t**)malloc(16 * sizeof(uint16_t*));
    if (!rows) return;
    for (int i = 0; i < 16; i++) {
        rows[i] = dst + indices[i] * (stride / sizeof(uint16_t));
    }
    for (y = 0; y < 16; y++) {
        (((av_alias64 *)(rows[y] + 0))->u64 = (dc));
        (((av_alias64 *)(rows[y] + 4))->u64 = (dc));
        (((av_alias64 *)(rows[y] + 8))->u64 = (dc));
        (((av_alias64 *)(rows[y] + 12))->u64 = (dc));
    }
    free(rows);
}
