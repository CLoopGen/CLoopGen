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
extern  uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access across rows with vertical data pattern (accessing same offset in each row)
    uint8_t *base = src;
    for (y = 0; y < 8; y++) {
        uint8_t *row = base + y * stride;
        ((av_alias32*)((uint32_t*)row))[0].u32 = dc;
        ((av_alias32*)((uint32_t*)row))[1].u32 = dc;
    }
}
