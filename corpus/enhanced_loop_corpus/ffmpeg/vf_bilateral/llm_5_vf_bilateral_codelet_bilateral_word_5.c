#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int dst_linesize;
extern uint16_t *dst;
extern float *img_out_f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < height; i++) {
        int skip_row = (i % 2) == 1;
        if (!skip_row) {
            for (int j = 0; j < width; j++) {
                dst[j + i * dst_linesize] = img_out_f[i * width + j];
            }
        }
    }
}
