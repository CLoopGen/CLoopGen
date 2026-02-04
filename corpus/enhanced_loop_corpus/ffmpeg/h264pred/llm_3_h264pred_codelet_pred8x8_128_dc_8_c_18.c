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
extern  uint32_t a;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating pattern (access every other row, double stride)
    for (i = 0; i < 8; i += 2) {
        uint8_t *row1 = src + i * stride;
        uint8_t *row2 = src + (i + 1) * stride;

        ((av_alias32 *)(((uint32_t *)row1) + 0))->u32 = a;
        ((av_alias32 *)(((uint32_t *)row1) + 1))->u32 = a;

        ((av_alias32 *)(((uint32_t *)row2) + 0))->u32 = a;
        ((av_alias32 *)(((uint32_t *)row2) + 1))->u32 = a;
    }
}
