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
    int j, i;
    uint16_t temp_r, temp_g, temp_b;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            temp_r = src_r[i];
            temp_g = src_g[i];
            temp_b = src_b[i];
            // Introduce temporary variables to break direct WAW and RAW hazards
            // and create local data dependency scope
            uint16_t new_r = (temp_r + temp_g - 512) & 1023;
            uint16_t new_b = (temp_b + temp_g - 512) & 1023;
            src_r[i] = new_r;
            src_b[i] = new_b;
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
