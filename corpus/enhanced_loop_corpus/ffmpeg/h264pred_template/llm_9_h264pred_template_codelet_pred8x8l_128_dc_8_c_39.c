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
for (y = 0; y < 4; y++) {
    uint32_t base_val = (1 << (7)) * 16843009U;
    uint32_t offset1 = base_val + 100;
    uint32_t offset2 = base_val - 100;
    ((av_alias32 *)(((uint32_t *)src) + 0))->u32 = offset1;
    ((av_alias32 *)(((uint32_t *)src) + 1))->u32 = offset2;
    ((av_alias32 *)(((uint32_t *)src) + 2))->u32 = offset1 ^ 0x12345678;
    ((av_alias32 *)(((uint32_t *)src) + 3))->u32 = offset2 ^ 0x87654321;
    src += stride;
}
}
