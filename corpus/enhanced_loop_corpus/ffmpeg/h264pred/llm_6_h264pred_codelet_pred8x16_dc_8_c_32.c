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
extern uint32_t dc0splat;
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_dc0 = dc0splat;
    uint32_t temp_dc1 = dc1splat;
    for (i = 0; i < 4; i++) {
        av_alias32 *ptr0 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 0);
        av_alias32 *ptr1 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 1);
        ptr0->u32 = temp_dc0;
        ptr1->u32 = temp_dc1;
    }
}
