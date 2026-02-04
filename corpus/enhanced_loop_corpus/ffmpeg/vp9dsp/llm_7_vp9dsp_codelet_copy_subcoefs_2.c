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

extern int16_t *out;
extern  int16_t *in;
extern int sz;
extern int sub;
extern int bit_depth;
extern int n;
extern  int16_t *scan;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t accumulator = 0;
    for (n = 0; n < sz * sz; n++) {
        int rc = scan[n], rcx = rc % sz, rcy = rc / sz;
        if (rcx >= sub || rcy >= sub)
            break;
        if (bit_depth == 8) {
            out[rc] = (int16_t)(in[rc] + (accumulator & 0xFFFF));
            accumulator += out[rc];
        } else {
            uint32_t val = ((const av_alias32 *)(&in[rc * 2]))->u32;
            accumulator ^= val;
            ((av_alias32 *)(&out[rc * 2]))->u32 = val ^ (accumulator >> 16);
        }
    }
}
