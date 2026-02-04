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

extern int y;
extern uint8_t *src;
extern int stride;
extern uint32_t a;
extern uint32_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 16; y += 2) {
    uint32_t *row = (uint32_t *)(src + y * stride);
    ((av_alias32 *)(row + 0))->u32 = a ^ 0x12345678;
    ((av_alias32 *)(row + 1))->u32 = b ^ 0x87654321;
    ((av_alias32 *)(row + 2))->u32 = a ^ 0xABCDEF01;
    ((av_alias32 *)(row + 3))->u32 = b ^ 0x10FEDCBA;
}
}
