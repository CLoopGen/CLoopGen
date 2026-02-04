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

extern uint8_t *src;
extern int stride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    uint32_t *src32 = (uint32_t*)src;
    for (int x = 0; x < 2; x++) {
        ((av_alias32*)(void*)(src32 + x))->u32 = ((1 << (8 - 1)) * 16843009U);
    }
    src += stride;
}
}
