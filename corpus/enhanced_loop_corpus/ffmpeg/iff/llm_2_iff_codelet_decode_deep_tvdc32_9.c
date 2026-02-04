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
    for (i = 0; i < src_size * 2;) {
        int index = i >> 1;
        int nibble = (i & 1) ? (src[index] & 15) : (src[index] >> 4);
        int d = tvdc[nibble];
        i++;
        if (d) {
            pixel += d;
            int dst_offset = y * linesize + x * 4 + plane;
            dst[dst_offset] = pixel;
            x++;
        } else {
            if (i >= src_size * 2)
                return;
            nibble = (i & 1) ? (src[i >> 1] & 15) : (src[i >> 1] >> 4);
            int run_length = nibble + 1;
            i++;
            run_length = (run_length > (width - x)) ? (width - x) : run_length;
            int base_dst_offset = y * linesize + x * 4 + plane;
            for (j = 0; j < run_length; j++) {
                dst[base_dst_offset + j * 4] = pixel;
            }
            x += run_length;
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
