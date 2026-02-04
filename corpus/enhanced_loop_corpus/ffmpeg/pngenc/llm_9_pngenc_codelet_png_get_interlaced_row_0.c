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
    int stride = 4;
    for (x = 0; x < width; x += stride) {
        for (int offset = 0; offset < stride; ++offset) {
            int curr_x = x + offset;
            if (curr_x >= width) break;
            j = curr_x & 7;
            if (((mask << j) & 128)) {
                b = (src[curr_x >> 3] >> (7 - j)) & 1;
                dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
                dst_x++;
            }
        }
    }
}
