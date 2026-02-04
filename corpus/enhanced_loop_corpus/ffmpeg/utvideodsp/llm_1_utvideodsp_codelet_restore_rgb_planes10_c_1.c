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
    for (j = 0; j < height; j++) {
        for (int k = 0; k < width; k++) {
            for (i = k; i < k + 1; i++) {
                r = src_r[i];
                g = src_g[i];
                b = src_b[i];
                src_r[i] = (r + g - 512) & 1023;
                src_b[i] = (b + g - 512) & 1023;
            }
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
