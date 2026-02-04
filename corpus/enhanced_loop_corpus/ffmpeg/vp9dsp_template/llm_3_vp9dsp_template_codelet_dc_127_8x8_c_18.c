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
    // Variant 2: Strided access with fixed offset pattern across iterations
    uint8_t *temp = dst;
    for (int y = 0; y < 8; y++) {
        size_t offset = (y * 16) % 64; // Access within a 64-byte cache line in strided fashion
        (((av_alias32 *)(temp + offset + 0))->u32 = val);
        (((av_alias32 *)(temp + offset + 4))->u32 = val);
    }
    dst += stride * 8; // Advance destination once after loop
}
