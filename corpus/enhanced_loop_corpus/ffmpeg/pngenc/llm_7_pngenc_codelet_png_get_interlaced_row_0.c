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
    int next_dst_x = dst_x;
    for (x = 0; x < width; x++) {
        j = (x & 7);
        int shifted_mask = mask << j;
        if ((shifted_mask & 128)) {
            int src_index = x >> 3;
            int bit_pos = 7 - j;
            b = (src[src_index] >> bit_pos) & 1;
            int dst_byte_offset = next_dst_x >> 3;
            int dst_bit_shift = 7 - (next_dst_x & 7);
            dst[dst_byte_offset] |= b << dst_bit_shift;
            next_dst_x++;
        }
    }
    dst_x = next_dst_x;
}
