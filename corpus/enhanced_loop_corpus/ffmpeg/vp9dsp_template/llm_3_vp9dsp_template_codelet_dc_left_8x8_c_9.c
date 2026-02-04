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
    // Variant 2: Strided access with alternating byte-level writes simulating non-contiguous alignment
    uint8_t *base = dst;
    for (y = 0; y < 8; y++) {
        uint8_t *p = base + y * stride;
        // Write dc in little-endian format across 4 bytes at offset 0 and 4
        p[0] = (dc >>  0) & 0xFF;
        p[1] = (dc >>  8) & 0xFF;
        p[2] = (dc >> 16) & 0xFF;
        p[3] = (dc >> 24) & 0xFF;
        p[4] = (dc >>  0) & 0xFF;
        p[5] = (dc >>  8) & 0xFF;
        p[6] = (dc >> 16) & 0xFF;
        p[7] = (dc >> 24) & 0xFF;
    }
}
