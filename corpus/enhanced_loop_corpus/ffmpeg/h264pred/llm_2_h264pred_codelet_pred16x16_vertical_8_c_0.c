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

extern int i;
extern uint8_t *src;
extern int stride;
extern  uint32_t a;
extern  uint32_t b;
extern  uint32_t c;
extern  uint32_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent locations in row-major order
    uint32_t *base = (uint32_t *)src;
    for (i = 0; i < 16; i++) {
        int offset = i * (stride / sizeof(uint32_t)); // convert stride to uint32_t units
        ((av_alias32 *)(base + offset + 0))->u32 = a;
        ((av_alias32 *)(base + offset + 1))->u32 = b;
        ((av_alias32 *)(base + offset + 2))->u32 = c;
        ((av_alias32 *)(base + offset + 3))->u32 = d;
    }
}
