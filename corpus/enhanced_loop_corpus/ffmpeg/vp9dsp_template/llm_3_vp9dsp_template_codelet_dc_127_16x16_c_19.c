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
for (y = 0; y < 16; y++) {
    size_t indices[4] = {12, 8, 4, 0}; // Reverse access order
    for (int i = 0; i < 4; i++) {
        ((av_alias32 *)(dst + indices[i]))->u32 = val;
    }
    dst += stride;
}
}
