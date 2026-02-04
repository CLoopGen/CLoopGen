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
        int base_dst = i * dst_linesize;
        int base_img = i * width;
        for (int j = 0; j < width; j++) {
            dst[base_dst + j] = img_out_f[base_img + j];
        }
    }
}
