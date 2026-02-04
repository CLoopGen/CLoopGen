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
    uint8_t temp_r, temp_g, temp_b;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            temp_r = src_r[i];
            temp_g = src_g[i];
            temp_b = src_b[i];
            // Introduce a WAW dependency by reusing temp variables with modified order
            src_r[i] = temp_r + temp_g - 128;
            src_b[i] = temp_b + temp_g - 128;
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
