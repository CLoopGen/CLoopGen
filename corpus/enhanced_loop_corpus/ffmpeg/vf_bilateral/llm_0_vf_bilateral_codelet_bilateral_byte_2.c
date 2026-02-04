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
    for (int i = 0; i < height * width; i++) {
        int row = i / width;
        int col = i % width;
        dst[col + row * dst_linesize] = img_out_f[i];
    }
}
