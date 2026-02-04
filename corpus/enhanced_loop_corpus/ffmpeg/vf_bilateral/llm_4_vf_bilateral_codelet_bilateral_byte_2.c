#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int dst_linesize;
extern uint8_t *dst;
extern float *img_out_f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < height; i++) {
        int row_start_dst = i * dst_linesize;
        int row_start_img = i * width;
        for (int j = 0; j < width; j++) {
            if (img_out_f[row_start_img + j] >= 0.0f) {
                dst[row_start_dst + j] = (uint8_t)(img_out_f[row_start_img + j] + 0.5f);
            } else {
                dst[row_start_dst + j] = 0;
            }
        }
    }
}
