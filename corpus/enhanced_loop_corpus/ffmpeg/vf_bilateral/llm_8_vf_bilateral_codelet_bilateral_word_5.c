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
for (int i = 0; i < height; i += 2) {
    for (int j = 0; j < width; j += 2) {
        int dst_idx1 = j + i * dst_linesize;
        int src_idx1 = i * width + j;
        dst[dst_idx1] = img_out_f[src_idx1];
        if (j + 1 < width) {
            dst[dst_idx1 + 1] = img_out_f[src_idx1 + 1];
        }
        if (i + 1 < height) {
            int dst_idx2 = j + (i + 1) * dst_linesize;
            int src_idx2 = (i + 1) * width + j;
            dst[dst_idx2] = img_out_f[src_idx2];
            if (j + 1 < width) {
                dst[dst_idx2 + 1] = img_out_f[src_idx2 + 1];
            }
        }
    }
}
}
