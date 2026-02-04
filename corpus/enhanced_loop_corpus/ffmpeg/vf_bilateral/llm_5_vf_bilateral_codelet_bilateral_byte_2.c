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
        int dst_index = i * dst_linesize;
        int src_index = i * width;
        for (int j = 0; j < width; j += 4) {
            // Unroll and apply clamping with control conditions
            float val0 = img_out_f[src_index + j];
            float val1 = img_out_f[src_index + j + 1];
            float val2 = img_out_f[src_index + j + 2];
            float val3 = img_out_f[src_index + j + 3];

            if (val0 >= 0.0f && val0 <= 255.0f) dst[dst_index + j] = (uint8_t)(val0 + 0.5f);
            else if (val0 < 0.0f) dst[dst_index + j] = 0;
            else dst[dst_index + j] = 255;

            if (j + 1 < width) {
                if (val1 >= 0.0f && val1 <= 255.0f) dst[dst_index + j + 1] = (uint8_t)(val1 + 0.5f);
                else if (val1 < 0.0f) dst[dst_index + j + 1] = 0;
                else dst[dst_index + j + 1] = 255;
            }

            if (j + 2 < width) {
                if (val2 >= 0.0f && val2 <= 255.0f) dst[dst_index + j + 2] = (uint8_t)(val2 + 0.5f);
                else if (val2 < 0.0f) dst[dst_index + j + 2] = 0;
                else dst[dst_index + j + 2] = 255;
            }

            if (j + 3 < width) {
                if (val3 >= 0.0f && val3 <= 255.0f) dst[dst_index + j + 3] = (uint8_t)(val3 + 0.5f);
                else if (val3 < 0.0f) dst[dst_index + j + 3] = 0;
                else dst[dst_index + j + 3] = 255;
            }
        }
    }
}
