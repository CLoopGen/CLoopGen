#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src_data;
extern int src_linesize;
extern uint8_t *dst_data;
extern int dst_linesize;
extern int src_w;
extern int src_h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < src_h / 2; ++y) {
    for (x = 0; x < src_w / 2; ++x) {
        int src_idx_base = (y << 1) * src_linesize;
        int src_idx_base_next = src_idx_base + src_linesize;
        int x2 = x << 1;

        uint8_t or_result = src_data[src_idx_base + x2];
        if (or_result == 0) {
            or_result |= src_data[src_idx_base + x2 + 1];
        }
        if (or_result == 0) {
            or_result |= src_data[src_idx_base_next + x2];
        }
        if (or_result == 0) {
            or_result |= src_data[src_idx_base_next + x2 + 1];
        }

        dst_data[(y * dst_linesize) + x] = (or_result != 0);
    }
}
}
