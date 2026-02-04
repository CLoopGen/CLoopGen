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
    for (n = 0; n < end_x; n += 8) {
        uint32_t v32_1 = a[n] * 16843009;
        uint32_t v32_2 = a[n + 2] * 16843009;
        (((av_alias32 *)(&a[n]))->u32 = (v32_1));
        (((av_alias32 *)(&a[n + 4]))->u32 = (v32_2));
    }
}
