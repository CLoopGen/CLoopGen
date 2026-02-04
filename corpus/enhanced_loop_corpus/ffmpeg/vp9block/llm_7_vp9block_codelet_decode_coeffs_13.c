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
    for (n = 0; n < end_y; n += 2) {
        uint32_t v32_1 = l[n] * 16843009;
        uint32_t v32_2 = l[n + 1] * 16843009; // Remove loop-carried dependency by working on independent elements
        (((av_alias32 *)(&l[n]))->u32 = (v32_1));
        (((av_alias32 *)(&l[n + 4]))->u32 = (v32_1));
        (((av_alias32 *)(&l[n + 1]))->u32 = (v32_2));
        (((av_alias32 *)(&l[n + 5]))->u32 = (v32_2));
    }
}
