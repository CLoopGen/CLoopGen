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

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < end_y; n += 16) {
        av_alias32 *p0 = (av_alias32 *)&l[n + 0];
        av_alias32 *p4 = (av_alias32 *)&l[n + 4];
        av_alias32 *p8 = (av_alias32 *)&l[n + 8];
        av_alias32 *p12 = (av_alias32 *)&l[n + 12];
        
        p0->u32 = (l[n + 0] * 16843009U);
        p4->u32 = (l[n + 4] * 16843009U);
        p8->u32 = (l[n + 8] * 16843009U);
        p12->u32 = (l[n + 12] * 16843009U);
    }
}
