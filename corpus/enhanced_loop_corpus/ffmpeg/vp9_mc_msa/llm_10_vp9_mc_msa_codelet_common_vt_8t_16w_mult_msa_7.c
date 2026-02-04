#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 5); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        {
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride] = src_tmp[i * src_stride];
                }
            }
            ;
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride + 1] = src_tmp[i * src_stride + 1];
                }
            }
            ;
        }
        ;
        {
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride + 2] = src_tmp[i * src_stride + 2];
                }
            }
            ;
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride + 3] = src_tmp[i * src_stride + 3];
                }
            }
            ;
        }
        ;
        dst_tmp += (4 * dst_stride);
        src_tmp += (4 * src_stride);
        {
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride] = src_tmp[i * src_stride];
                }
            }
            ;
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride + 1] = src_tmp[i * src_stride + 1];
                }
            }
            ;
        }
        ;
        {
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride + 2] = src_tmp[i * src_stride + 2];
                }
            }
            ;
            {
                uint32_t i;
                for (i = 0; i < 4; ++i) {
                    dst_tmp[i * dst_stride + 3] = src_tmp[i * src_stride + 3];
                }
            }
            ;
        }
        ;
        dst_tmp += (4 * dst_stride);
        src_tmp += (4 * src_stride);
    }
    src += 32;
    dst += 32;
}
}
