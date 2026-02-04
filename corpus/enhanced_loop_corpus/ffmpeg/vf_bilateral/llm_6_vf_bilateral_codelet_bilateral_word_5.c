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
    uint16_t *dst_ptr = dst;
    float *src_ptr = img_out_f;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            dst_ptr[j] = (uint16_t)src_ptr[j];
        }
        dst_ptr += dst_linesize;
        src_ptr += width;
    }
}
