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
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed offset pattern using a lookup table for indirect-like indexing
    const int offsets[4] = {0, 4, 8, 12};
    for (i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            ((av_alias32 *)(src + offsets[j]))->u32 = (((1 << (8 - 1)) - 1) * 16843009U);
        }
        src += stride;
    }
}
