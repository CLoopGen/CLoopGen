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
        int base_dst_idx = i * dst_linesize;
        int base_img_idx = i * width;
        for (int j = 0; j < width; j++) {
            dst[base_dst_idx + j] = img_out_f[base_img_idx + j];
        }
    }
}
