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
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t *src_vec[4], *dst_vec[4];
    int i;
    for (i = 0; i < 4; ++i) {
        src_vec[i] = src_tmp + i * src_stride;
        dst_vec[i] = dst_tmp + i * dst_stride;
    }
    src_tmp += (7 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (i = 0; i < 4; ++i) {
            __builtin_memcpy(&dst_vec[i][0], &src_vec[i][0], 16);
        }
        for (i = 0; i < 4; ++i) {
            src_vec[i] += (4 * src_stride);
            dst_vec[i] += (4 * dst_stride);
        }
    }
    src += 16;
    dst += 16;
}
}
