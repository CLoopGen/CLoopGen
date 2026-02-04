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
for (i = 0; i < 32; i += 2) {
    uint8_t *row1 = src + i * stride;
    uint8_t *row2 = src + (i + 1) * stride;
    ((av_alias32 *)(((uint32_t *)row1) + 0))->u32 = a;
    ((av_alias32 *)(((uint32_t *)row1) + 1))->u32 = b;
    ((av_alias32 *)(((uint32_t *)row1) + 2))->u32 = c;
    ((av_alias32 *)(((uint32_t *)row1) + 3))->u32 = d;
    ((av_alias32 *)(((uint32_t *)row2) + 0))->u32 = a;
    ((av_alias32 *)(((uint32_t *)row2) + 1))->u32 = b;
    ((av_alias32 *)(((uint32_t *)row2) + 2))->u32 = c;
    ((av_alias32 *)(((uint32_t *)row2) + 3))->u32 = d;
}
}
