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
for (y = 0; y < 4; y++) {
    uint32_t temp1 = dc + 1;
    uint32_t temp2 = dc ^ 0xFFFFFFFF;
    (((av_alias32 *)(((uint32_t *)src) + 0))->u32 = (temp1));
    (((av_alias32 *)(((uint32_t *)src) + 1))->u32 = (temp2));
    src += stride;
    (((av_alias32 *)(((uint32_t *)src) + 0))->u32 = (temp2));
    (((av_alias32 *)(((uint32_t *)src) + 1))->u32 = (temp1));
    src += stride;
}
}
