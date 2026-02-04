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
extern uint32_t p4a;
extern uint32_t p4b;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed write order (interleaved store pattern)
    uint8_t *d = dst;
    for (y = 0; y < 8; y++) {
        ((av_alias32 *)(d + 0))->u32 = (y & 1) ? p4b : p4a;
        ((av_alias32 *)(d + 4))->u32 = (y & 1) ? p4a : p4b;
        d += stride;
    }
}
