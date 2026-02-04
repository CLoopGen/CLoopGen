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
    // Variant 2: Strided access with fixed step through pointer arithmetic (simulating cache line alignment effects)
    uint8_t *row = src;
    ptrdiff_t element_size = 2 * sizeof(uint32_t); // Two u32 per iteration
    for (i = 0; i < 4; i++) {
        ((av_alias32 *)(row + 0))->u32 = dc0splat;
        ((av_alias32 *)(row + sizeof(uint32_t)))->u32 = dc0splat;
        row += stride;
    }
}
