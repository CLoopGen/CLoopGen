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
    for (n = 0; n < end_x; n += 4) {
        av_alias32 *p1 = (av_alias32 *)(&a[n]);
        av_alias32 *p2 = (av_alias32 *)(&a[n + 2]);
        p1->u32 = (a[n] * 16843009U);
        if (n + 2 < end_x) {
            p2->u32 = (a[n + 2] * 16843009U);
        }
    }
}
