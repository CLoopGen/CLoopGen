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
    for (; n < sz * sz; n++) {
        int rc = scan[n];
        if (bit_depth == 8) {
            out[rc] = 0;
        } else {
            ((av_alias32 *)(&out[rc * 2]))->u32 = 0;
        }
    }
}
