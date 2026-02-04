#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 5); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 4); loop_cnt--;) {
        for (int i = 0; i < 4; ++i) {
            {
                uint8_t val1 = src_tmp[(i*2+0) * src_stride + (i*2+0)];
                uint8_t val2 = src_tmp[(i*2+0) * src_stride + (i*2+1)];
                uint8_t val3 = src_tmp[(i*2+1) * src_stride + (i*2+0)];
                uint8_t val4 = src_tmp[(i*2+1) * src_stride + (i*2+1)];
                uint32_t product = (uint32_t)val1 * val2 * val3 * val4;
                uint8_t result = (product > 255) ? 255 : (uint8_t)product;
                dst_tmp[i * dst_stride + i] = result;
            }
            {
                uint8_t neighbor_sum = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int y_idx = (i*2) + dy;
                        int x_idx = (i*2) + dx;
                        if (y_idx >= 0 && y_idx < height && x_idx >= 0 && x_idx < width) {
                            neighbor_sum += src_tmp[y_idx * src_stride + x_idx];
                        }
                    }
                }
                dst_tmp[(i+4) * dst_stride + i] = neighbor_sum;
            }
        }
        src_tmp += (8 * src_stride);
        dst_tmp += (8 * dst_stride);
    }
    src += 32;
    dst += 32;
}
}
