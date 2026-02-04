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
    for (int stride = 4; stride <= end_x; stride <<= 1) {
        for (n = 0; n < end_x; n += stride) {
            (((av_alias32 *)(&a[n]))->u32 = (a[n] * 16843009));
        }
        if (stride >= end_x) break;
    }
    // Final pass to ensure all elements are covered in case of non-power-of-two sizes
    for (n = 0; n < end_x; n += 4) {
        (((av_alias32 *)(&a[n]))->u32 = (a[n] * 16843009));
    }
}
