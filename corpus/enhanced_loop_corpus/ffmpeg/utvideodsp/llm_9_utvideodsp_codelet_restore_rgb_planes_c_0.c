#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_r;
extern uint8_t *src_g;
extern uint8_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < height; j += 2) {
        for (i = 0; i < width; i++) {
            r = src_r[i];
            g = src_g[i];
            b = src_b[i];
            src_r[i] = ((r + g - 128) << 1) >> 1;
            src_b[i] = ((b + g - 128) * 3) / 3;

            if (j + 1 < height) {
                uint8_t r_next = src_r[linesize_r + i];
                uint8_t g_next = src_g[linesize_g + i];
                uint8_t b_next = src_b[linesize_b + i];
                src_r[linesize_r + i] = r_next + g_next - 128;
                src_b[linesize_b + i] = b_next + g_next - 128;
            }
        }
        src_r += 2 * linesize_r;
        src_g += 2 * linesize_g;
        src_b += 2 * linesize_b;
    }
}
