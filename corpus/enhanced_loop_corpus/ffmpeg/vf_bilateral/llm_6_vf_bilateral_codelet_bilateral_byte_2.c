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
        int base_dst_idx = i * dst_linesize;
        int base_img_idx = i * width;
        for (int j = 0; j < width; j++) {
            int dst_idx = base_dst_idx + j;
            int src_idx = base_img_idx + j;
            // Introduce a temporary variable to modify data dependency (WAW and RAW introduced locally)
            float temp_val = img_out_f[src_idx];
            uint8_t converted_val = (uint8_t)temp_val;
            dst[dst_idx] = converted_val;
        }
    }
}
