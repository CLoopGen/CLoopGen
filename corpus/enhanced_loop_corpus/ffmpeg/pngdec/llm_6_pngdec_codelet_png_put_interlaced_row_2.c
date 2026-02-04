#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern  uint8_t *src;
extern int x;
extern int mask;
extern int dsp_mask;
extern int j;
extern int src_x;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_src_x = src_x;
    for (x = 0; x < width; x++) {
        int j2 = 2 * (x & 3);
        j = (x & 7);
        int shifted_dsp_mask = dsp_mask << j;
        int shifted_mask = mask << j;
        if (shifted_dsp_mask & 128) {
            int effective_index = prev_src_x >> 2;
            int shift_amount = 6 - 2 * (prev_src_x & 3);
            b = (src[effective_index] >> shift_amount) & 3;
            dst[x >> 2] &= 65343 >> j2;
            dst[x >> 2] |= b << (6 - j2);
        }
        if (shifted_mask & 128)
            prev_src_x++;
    }
    src_x = prev_src_x;
}
