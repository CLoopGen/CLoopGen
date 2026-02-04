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
    uint32_t temp_val = ((1 << (8 - 1)) * 16843009U);
    for (y = 0; y < 8; y++) {
        av_alias32 *ptr0 = (av_alias32*)(((uint32_t *)src) + 0);
        av_alias32 *ptr1 = (av_alias32*)(((uint32_t *)src) + 1);
        ptr0->u32 = temp_val;
        ptr1->u32 = ptr0->u32; // Introduce RAW dependency: use of ptr0->u32 just after write
        src += stride;
    }
}
