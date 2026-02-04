#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t width;
extern int32_t height;
extern uint8_t *src_orig;
extern uint8_t *dst_orig;
extern int32_t h_cnt;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
    for (h_cnt = 0; h_cnt < (height >> 2); ++h_cnt) {
        uint8_t* s_row = src_orig + v_cnt + (h_cnt << 2) * src_stride;
        uint8_t* d_row = dst_orig + v_cnt + (h_cnt << 2) * dst_stride;
        for (int offset = 0; offset < 16; ++offset) {
            d_row[offset + 0 * dst_stride] = s_row[offset + 0 * src_stride];
            d_row[offset + 1 * dst_stride] = s_row[offset + 1 * src_stride];
            d_row[offset + 2 * dst_stride] = s_row[offset + 2 * src_stride];
            d_row[offset + 3 * dst_stride] = s_row[offset + 3 * src_stride];
        }
    }
}
}
