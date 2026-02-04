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
for (n = 0; n < end_y; n += 4) {
    if (n + 2 >= end_y) break;
    uint32_t v32_0 = l[n] * 16843009;
    uint32_t v32_1 = l[n + 2] * 16843009;
    (((av_alias32 *)(&l[n]))->u32 = (v32_0));
    (((av_alias32 *)(&l[n + 4]))->u32 = (v32_0));
    (((av_alias32 *)(&l[n + 2]))->u32 = (v32_1));
    (((av_alias32 *)(&l[n + 6]))->u32 = (v32_1));
}
}
