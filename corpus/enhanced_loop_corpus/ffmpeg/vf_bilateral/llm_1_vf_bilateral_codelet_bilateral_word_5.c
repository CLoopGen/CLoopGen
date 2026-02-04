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
    int idx = 0;
    for (int ij = 0; ij < height * width; ij++) {
        int i = ij / width;
        int j = ij % width;
        dst[j + i * dst_linesize] = img_out_f[ij];
    }
}
