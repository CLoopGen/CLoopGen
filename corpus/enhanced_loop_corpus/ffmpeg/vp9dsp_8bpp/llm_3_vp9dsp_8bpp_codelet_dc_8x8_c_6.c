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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating offset pattern
    // Access memory using a non-uniform stride pattern: alternate between two different offsets
    // Simulates irregular but predictable access, possibly mimicking interlaced or tiled layout
    uint8_t *base = dst;
    for (y = 0; y < 8; y++) {
        int offset = (y & 1) ? 2 : 6; // Alternate offset: 2 or 6 bytes from base
        (((av_alias32 *)(base + offset))->u32 = (dc));
        (((av_alias32 *)(base + offset + 4))->u32 = (dc));
        base += stride;
    }
}
