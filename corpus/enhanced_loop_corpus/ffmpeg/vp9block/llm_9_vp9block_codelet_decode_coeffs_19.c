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
    for (n = 0; n < end_x; n += 2) {
        uint32_t v32 = a[n] * 16843009U;
        uint32_t v32_adj = (v32 >> 8) | (v32 << 24);
        (((av_alias32 *)(&a[n]))->u32 = (v32));
        (((av_alias32 *)(&a[n + 4]))->u32 = (v32_adj));
        if (n + 2 < end_x) {
            (((av_alias32 *)(&a[n + 2]))->u32 = (v32 ^ 0x80808080));
            (((av_alias32 *)(&a[n + 6]))->u32 = (v32_adj ^ 0x80808080));
        }
    }
}
