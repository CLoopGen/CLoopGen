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

extern  uint8_t *in1;
extern  uint8_t *in2;
extern uint8_t *out;
extern int i;
extern int n;
extern uint32_t v1;
extern uint32_t v2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        uint32_t v1a, v1b, v2a, v2b;
        v1a = (((const av_alias32 *)(in1 + 0))->u32);
        v2a = (((const av_alias32 *)(in2 + 0))->u32);
        v1b = (((const av_alias32 *)(in1 + 4))->u32);
        v2b = (((const av_alias32 *)(in2 + 4))->u32);
        (((av_alias32 *)(out + 0))->u32) = (v1a ^ v2a);
        (((av_alias32 *)(out + 4))->u32) = (v1b ^ v2b);
        in1 += 8;
        in2 += 8;
        out += 8;
    }
}
