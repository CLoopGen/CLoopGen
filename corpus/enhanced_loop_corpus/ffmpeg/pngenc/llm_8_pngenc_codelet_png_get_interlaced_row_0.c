#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int x;
extern int mask;
extern int dst_x;
extern int j;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < width; x += 2) {
        j = (x & 7);
        int shift1 = mask << j;
        if (shift1 & 128) {
            int src_idx = x >> 3;
            int bit_pos = 7 - j;
            b = (src[src_idx] >> bit_pos) & 1;
            int dst_idx = dst_x >> 3;
            int dst_bit = 7 - (dst_x & 7);
            dst[dst_idx] |= b << dst_bit;
            dst_x++;
        }
        if ((x + 1) < width) {
            int j2 = ((x + 1) & 7);
            if ((mask << j2) & 128) {
                int src_idx2 = (x + 1) >> 3;
                int bit_pos2 = 7 - j2;
                b = (src[src_idx2] >> bit_pos2) & 1;
                int dst_idx2 = dst_x >> 3;
                int dst_bit2 = 7 - (dst_x & 7);
                dst[dst_idx2] |= b << dst_bit2;
                dst_x++;
            }
        }
    }
}
