#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int src_size;
extern int width;
extern int height;
extern int linesize;
extern  int16_t *tvdc;
extern int x;
extern int y;
extern int plane;
extern int8_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect access via pointer arithmetic for src and dst to modify memory access pattern
    uint8_t *src_ptr = src;
    uint8_t *dst_base = dst;
    int remaining_bits = src_size * 2;
    i = 0;

    while (i < remaining_bits) {  // Note: using 'while' to avoid for-loop, but logic equivalent
        int half_i = i >> 1;
        uint8_t byte_val = *(src_ptr + half_i);
        uint8_t nibble = (i & 1) ? (byte_val & 15) : (byte_val >> 4);
        int d = tvdc[nibble];
        i++;

        if (d) {
            pixel += d;
            int offset = y * linesize + x * 4 + plane;
            *(dst_base + offset) = pixel;
            x++;
        } else {
            if (i >= remaining_bits)
                return;
            half_i = i >> 1;
            byte_val = *(src_ptr + half_i);
            nibble = (i & 1) ? (byte_val & 15) : (byte_val >> 4);
            int run = nibble + 1;
            i++;
            run = (run > (width - x)) ? (width - x) : run;
            int dst_offset = y * linesize + x * 4 + plane;
            for (j = 0; j < run; j++) {
                *(dst_base + dst_offset + j * 4) = pixel;
            }
            x += run;
        }

        if (x >= width) {
            plane++;
            if (plane >= 4) {
                y++;
                if (y >= height)
                    return;
                plane = 0;
            }
            x = 0;
            pixel = 0;
            i = (i + 1) & ~1;
        }
    }
}
