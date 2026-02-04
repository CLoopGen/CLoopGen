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
        if (i + 1 < n) {
            // Unrolled to process two iterations per loop body (increased logical depth via unrolling)
            v1 = (((const av_alias32 *)(in1))->u32);
            v2 = (((const av_alias32 *)(in2))->u32);
            (((av_alias32 *)(out))->u32) = (v1 ^ v2);
            in1 += 4;
            in2 += 4;
            out += 4;

            v1 = (((const av_alias32 *)(in1))->u32);
            v2 = (((const av_alias32 *)(in2))->u32);
            (((av_alias32 *)(out))->u32) = (v1 ^ v2);
            in1 += 4;
            in2 += 4;
            out += 4;
        } else {
            // Handle leftover element
            v1 = (((const av_alias32 *)(in1))->u32);
            v2 = (((const av_alias32 *)(in2))->u32);
            (((av_alias32 *)(out))->u32) = (v1 ^ v2);
            in1 += 4;
            in2 += 4;
            out += 4;
        }
    }
}
