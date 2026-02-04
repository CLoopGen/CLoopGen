#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern int i;
extern uint32_t dc0splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed indexing
    // Access elements in a column-wise (transposed) manner using fixed offsets within each row
    // Simulates processing one component across multiple pixels with larger stride steps
    uint8_t *row_start;
    for (i = 0; i < 4; i++) {
        row_start = src + i;
        (((av_alias32 *)(((uint32_t *)(row_start + 0 * stride)) + 0))->u32 = (dc0splat));
        (((av_alias32 *)(((uint32_t *)(row_start + 1 * stride)) + 0))->u32 = (dc0splat));
        (((av_alias32 *)(((uint32_t *)(row_start + 2 * stride)) + 0))->u32 = (dc0splat));
        (((av_alias32 *)(((uint32_t *)(row_start + 3 * stride)) + 0))->u32 = (dc0splat));
    }
}
