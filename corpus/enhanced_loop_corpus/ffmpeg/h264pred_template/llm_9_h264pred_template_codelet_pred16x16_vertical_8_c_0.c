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
for (i = 0; i < 8; i++) {
    uint8_t *base = src + i * stride * 2;
    uint32_t temp_a = a ^ 0x12345678;
    uint32_t temp_b = b + 0xABCDEF01;
    uint32_t temp_c = c ^ 0xCAFEBABE;
    uint32_t temp_d = d - 0xFEDCBA98;
    ((av_alias32 *)(((uint32_t *)base) + 0))->u32 = temp_a;
    ((av_alias32 *)(((uint32_t *)base) + 1))->u32 = temp_b;
    ((av_alias32 *)(((uint32_t *)base) + 2))->u32 = temp_c;
    ((av_alias32 *)(((uint32_t *)base) + 3))->u32 = temp_d;
    base += stride;
    ((av_alias32 *)(((uint32_t *)base) + 0))->u32 = temp_a;
    ((av_alias32 *)(((uint32_t *)base) + 1))->u32 = temp_b;
    ((av_alias32 *)(((uint32_t *)base) + 2))->u32 = temp_c;
    ((av_alias32 *)(((uint32_t *)base) + 3))->u32 = temp_d;
}
}
