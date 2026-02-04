#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 0) {
        for (i = 0; i < width; i += 2) {
            int unrolled_i;
            for (unrolled_i = i; unrolled_i < i + 2 && unrolled_i < width; unrolled_i++) {
                int offset_src = (unrolled_i - i);
                int offset_dst = offset_src * 3;
                uint8_t val_top = src[(offset_src == 0 ? 0 : 1) * src_stride + 1 * (1)];
                uint8_t val_bot = src[(offset_src == 0 ? 0 : 1) * src_stride + 1 * (0)];
                dst[(0) * dst_stride + (0 + offset_dst) * 3 + 2] = dst[(0) * dst_stride + (1 + offset_dst) * 3 + 2] =
                dst[(1) * dst_stride + (1 + offset_dst) * 3 + 2] = dst[(1) * dst_stride + (0 + offset_dst) * 3 + 2] = val_top >> 0;
                dst[(0) * dst_stride + (1 + offset_dst) * 3 + 1] = val_top >> 0;
                dst[(0) * dst_stride + (0 + offset_dst) * 3 + 1] = dst[(1) * dst_stride + (1 + offset_dst) * 3 + 1] =
                    ((unsigned int)val_top + (unsigned int)val_bot) >> 1;
                dst[(1) * dst_stride + (0 + offset_dst) * 3 + 1] = val_bot >> 0;
                dst[(1) * dst_stride + (1 + offset_dst) * 3 + 0] = dst[(0) * dst_stride + (0 + offset_dst) * 3 + 0] =
                dst[(0) * dst_stride + (1 + offset_dst) * 3 + 0] = dst[(1) * dst_stride + (0 + offset_dst) * 3 + 0] = val_bot >> 0;
            }
            src += 2 * 1;
            dst += 6;
        }
    }
}
