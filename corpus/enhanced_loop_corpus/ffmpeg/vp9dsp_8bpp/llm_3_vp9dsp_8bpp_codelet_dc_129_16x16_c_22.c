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
extern uint8_t *dst;
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with vertical stepping
    // Instead of writing 4 horizontal elements per row, write one element per row
    // but across multiple columns with non-unit stride, effectively creating a transposed store pattern.
    // Each iteration writes only one 32-bit value, but loops over 64 iterations conceptually grouped in 4x16
    // However, we maintain 16 iterations with step of 4 in destination offset each time.
    uint8_t *base = dst;
    for (y = 0; y < 16; y++) {
        (((av_alias32 *)(base + 0 * stride))->u32 = (val));
        (((av_alias32 *)(base + 1 * stride))->u32 = (val));
        (((av_alias32 *)(base + 2 * stride))->u32 = (val));
        (((av_alias32 *)(base + 3 * stride))->u32 = (val));
        base += 4; // Move horizontally by 4 bytes after vertical column writes
    }
}
