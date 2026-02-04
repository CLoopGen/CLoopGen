#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int i = 0; i < 2; i++) {
            {
                {
                    // Simulated computation: byte-wise addition with stride traversal
                    uint8_t temp1 = src[i * src_stride + 0];
                    uint8_t temp2 = src[i * src_stride + 1];
                    dst[i * dst_stride + 0] = temp1 ^ 0xFF;
                    dst[i * dst_stride + 1] = temp2 ^ 0xFF;
                }
                ;
                {
                    uint8_t temp3 = src[i * src_stride + 2];
                    uint8_t temp4 = src[i * src_stride + 3];
                    dst[i * dst_stride + 2] = temp3 ^ 0xFF;
                    dst[i * dst_stride + 3] = temp4 ^ 0xFF;
                }
                ;
            }
            ;
            {
                {
                    uint8_t temp5 = src[i * src_stride + 4];
                    uint8_t temp6 = src[i * src_stride + 5];
                    dst[i * dst_stride + 4] = temp5 ^ 0xFF;
                    dst[i * dst_stride + 5] = temp6 ^ 0xFF;
                }
                ;
                {
                    uint8_t temp7 = src[i * src_stride + 6];
                    uint8_t temp8 = src[i * src_stride + 7];
                    dst[i * dst_stride + 6] = temp7 ^ 0xFF;
                    dst[i * dst_stride + 7] = temp8 ^ 0xFF;
                }
                ;
            }
            ;
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
