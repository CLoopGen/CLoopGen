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
    int stride = 2;
    for (n = 0; n < end_y; n += 4 * stride) {
        int i0 = n * stride;
        int i1 = n * stride + 1;
        int i2 = n * stride + 2;
        int i3 = n * stride + 3;
        if (i3 < end_y) {
            ((av_alias32 *)(&l[i0]))->u32 = (l[i0] * 16843009);
            ((av_alias32 *)(&l[i1]))->u32 = (l[i1] * 16843009);
            ((av_alias32 *)(&l[i2]))->u32 = (l[i2] * 16843009);
            ((av_alias32 *)(&l[i3]))->u32 = (l[i3] * 16843009);
        }
    }
}
