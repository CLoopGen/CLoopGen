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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    uint32_t *row1 = (uint32_t *)(src + i * stride);
    uint32_t *row2 = (uint32_t *)(src + (i + 1) * stride);
    ((av_alias32 *)row1)->u32 = a ^ 0x12345678;
    ((av_alias32 *)(row1 + 1))->u32 = b ^ 0x87654321;
    ((av_alias32 *)row2)->u32 = a ^ 0xABCDEF01;
    ((av_alias32 *)(row2 + 1))->u32 = b ^ 0x10FEDCBA;
}
}
