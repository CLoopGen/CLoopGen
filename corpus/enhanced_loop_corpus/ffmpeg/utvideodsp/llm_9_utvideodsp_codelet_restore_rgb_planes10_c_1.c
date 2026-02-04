#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *src_r;
extern uint16_t *src_g;
extern uint16_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern int r;
extern int g;
extern int b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < height; j += 2) {
    for (i = 0; i < width; i++) {
        r = src_r[i];
        g = src_g[i];
        b = src_b[i];
        src_r[i] = ((r << 1) + g - 768) & 1023;
        src_b[i] = (b + (g << 1) - 768) & 1023;

        if (j + 1 < height) {
            int offset_r = linesize_r / sizeof(uint16_t);
            int offset_g = linesize_g / sizeof(uint16_t);
            int offset_b = linesize_b / sizeof(uint16_t);
            uint16_t* r_ptr_next = src_r + offset_r;
            uint16_t* g_ptr_next = src_g + offset_g;
            uint16_t* b_ptr_next = src_b + offset_b;

            r = r_ptr_next[i];
            g = g_ptr_next[i];
            b = b_ptr_next[i];
            r_ptr_next[i] = (r + g - 256) & 1023;
            b_ptr_next[i] = (b + g - 256) & 1023;
        }
    }
    src_r += linesize_r * 2;
    src_g += linesize_g * 2;
    src_b += linesize_b * 2;
}
}
