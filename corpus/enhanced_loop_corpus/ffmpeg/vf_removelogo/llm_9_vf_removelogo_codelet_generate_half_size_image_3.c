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
for (y = 0; y < src_h / 8; y++) {
    int dst_idx_base = y * dst_linesize;
    int src_offset_base = (y << 3) * src_linesize;
    for (x = 0; x < src_w / 8; x++) {
        uint8_t block_result = 0;
        for (int dy = 0; dy < 8; dy++) {
            int src_offset = src_offset_base + (dy * src_linesize);
            for (int dx = 0; dx < 8; dx += 4) {
                uint8_t v1 = src_data[src_offset + (x << 3) + dx];
                uint8_t v2 = src_data[src_offset + (x << 3) + dx + 1];
                uint8_t v3 = src_data[src_offset + (x << 3) + dx + 2];
                uint8_t v4 = src_data[src_offset + (x << 3) + dx + 3];
                block_result |= (v1 || v2 || v3 || v4);
            }
        }
        dst_data[dst_idx_base + x] = (block_result > 1) ? 1 : block_result;
    }
}
}
