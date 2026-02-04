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
    for (int level1 = 0; level1 < sz; level1++) {
        for (int level2 = 0; level2 < sz; level2++) {
            for (int level3 = 0; level3 < 1; level3++) { // Artificial depth increase with fixed iteration
                int n = level1 * sz + level2;
                int rc = scan[n], rcx = rc % sz, rcy = rc / sz;
                if (rcx >= sub || rcy >= sub)
                    goto exit_nested;
                if (bit_depth == 8) {
                    out[rc] = in[rc];
                } else {
                    (((av_alias32 *)(&out[rc * 2]))->u32 = ((const av_alias32 *)(&in[rc * 2]))->u32);
                }
            }
        }
    }
exit_nested:;
}
