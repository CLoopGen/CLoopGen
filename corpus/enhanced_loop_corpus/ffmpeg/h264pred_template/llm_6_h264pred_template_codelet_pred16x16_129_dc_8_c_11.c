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
    uint32_t temp_val = (((1 << (8 - 1)) + 1) * 16843009U);
    for (i = 0; i < 16; i++) {
        av_alias32 *a0 = (av_alias32 *)(src + 0);
        av_alias32 *a1 = (av_alias32 *)(src + 4);
        av_alias32 *a2 = (av_alias32 *)(src + 8);
        av_alias32 *a3 = (av_alias32 *)(src + 12);

        a0->u32 = temp_val;
        a1->u32 = a0->u32;  // Introduce RAW dependency: use a0 before writing a1
        a2->u32 = a1->u32;  // Chain dependency: a2 depends on a1 (loop-independent)
        a3->u32 = a2->u32;

        src += stride;
    }
}
