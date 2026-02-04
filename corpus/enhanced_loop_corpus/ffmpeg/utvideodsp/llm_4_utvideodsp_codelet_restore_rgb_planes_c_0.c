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
    for (j = 0; j < height; j++) {
        if (j % 2 == 0) {
            for (i = 0; i < width; i++) {
                r = src_r[i];
                g = src_g[i];
                b = src_b[i];
                src_r[i] = r + g - 128;
                src_b[i] = b + g - 128;
            }
        } else {
            for (i = 0; i < width; i++) {
                r = src_r[i];
                g = src_g[i];
                b = src_b[i];
                // Skip updating src_r on odd rows, only update src_b
                src_b[i] = b + g - 128;
            }
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
