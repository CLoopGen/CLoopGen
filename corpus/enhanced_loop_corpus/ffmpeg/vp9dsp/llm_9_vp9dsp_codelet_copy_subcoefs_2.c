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
    for (n = 0; n < sz * sz && n < 2 * sub; n += 2) {
        int rc1 = scan[n], rcx1 = rc1 % sz, rcy1 = rc1 / sz;
        if (!(rcx1 >= sub || rcy1 >= sub)) {
            if (bit_depth == 8) {
                out[rc1] = in[rc1];
            } else {
                (((av_alias32 *)(&out[rc1 * 2]))->u32 = ((const av_alias32 *)(&in[rc1 * 2]))->u32);
            }
        }
        if (n + 1 < sz * sz && n + 1 < 2 * sub) {
            int rc2 = scan[n + 1], rcx2 = rc2 % sz, rcy2 = rc2 / sz;
            if (!(rcx2 >= sub || rcy2 >= sub)) {
                if (bit_depth == 8) {
                    out[rc2] = in[rc2];
                } else {
                    (((av_alias32 *)(&out[rc2 * 2]))->u32 = ((const av_alias32 *)(&in[rc2 * 2]))->u32);
                }
            }
        }
    }
}
