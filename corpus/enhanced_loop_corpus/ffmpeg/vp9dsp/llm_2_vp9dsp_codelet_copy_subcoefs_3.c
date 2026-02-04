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
extern int sz;
extern int bit_depth;
extern int n;
extern  int16_t *scan;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with stride handling
    int stride = (bit_depth == 8) ? 1 : 2;
    for (; n < sz * sz; n++) {
        int rc = scan[n];
        int base_idx = rc * stride;
        if (bit_depth == 8) {
            out[base_idx] = 0;
        } else {
            ((av_alias32*)&out[base_idx])->u32 = 0;
        }
    }
}
