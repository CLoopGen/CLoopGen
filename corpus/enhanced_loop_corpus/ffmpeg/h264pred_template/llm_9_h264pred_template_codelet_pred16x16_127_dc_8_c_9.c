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

extern ptrdiff_t stride;
extern int i;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint32_t base_val = ((1 << (8 - 1)) - 1) * 16843009U;
    uint32_t shift_val = (base_val >> 1) ^ 0xAAAAAAAA;
    uint32_t xor_val = base_val ^ 0xFFFF0000;
    for (int j = 0; j < 2; j++) {
        (((av_alias32 *)(src + 0 + j * 16))->u32 = base_val);
        (((av_alias32 *)(src + 4 + j * 16))->u32 = shift_val);
        (((av_alias32 *)(src + 8 + j * 16))->u32 = xor_val);
        (((av_alias32 *)(src + 12 + j * 16))->u32 = (base_val + j * 0x100));
    }
    src += stride;
}
}
