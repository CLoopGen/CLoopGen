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
    int base_dst = i * dst_linesize;
    int base_src = i * width;
    for (int j = 0; j < width; j++) {
        float val = img_out_f[base_src + j];
        uint16_t clamped = (val < 0) ? 0 : (val > 65535) ? 65535 : (uint16_t)val;
        dst[base_dst + j] = clamped;
    }
}
}
