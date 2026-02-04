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
        int index1 = n;
        int index2 = (n + 4) % end_x;
        uint32_t v32 = a[index1] * 16843009;
        (((av_alias32 *)(&a[index1]))->u32 = (v32));
        (((av_alias32 *)(&a[index2]))->u32 = (v32));
    }
}
