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

extern uint8_t *dst;
extern int linesize;
extern uint32_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening 2D indices into a linear pattern
    uint8_t *base = dst;
    for (int idx = 0; idx < 16; idx++) {
        int j = idx >> 2;  // Equivalent to idx / 4
        int i = idx & 3;   // Equivalent to idx % 4
        ((av_alias32 *)(base + j * linesize + i * 4))->u32 = pixel;
    }
}
