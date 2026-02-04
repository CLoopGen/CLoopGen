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

extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < end_x - 7; n += 8) {
        av_alias32 *p0 = (av_alias32 *)&a[n + 0];
        av_alias32 *p4 = (av_alias32 *)&a[n + 4];
        p0->u32 = (uint32_t)(a[n + 0] * 16843009U);
        p0->u32 += (uint32_t)(a[n + 1] * 16843009U) << 8;
        p0->u32 += (uint32_t)(a[n + 2] * 16843009U) << 16;
        p0->u32 += (uint32_t)(a[n + 3] * 16843009U) << 24;
        p4->u32 = (uint32_t)(a[n + 4] * 16843009U);
        p4->u32 += (uint32_t)(a[n + 5] * 16843009U) << 8;
        p4->u32 += (uint32_t)(a[n + 6] * 16843009U) << 16;
        p4->u32 += (uint32_t)(a[n + 7] * 16843009U) << 24;
    }
}
