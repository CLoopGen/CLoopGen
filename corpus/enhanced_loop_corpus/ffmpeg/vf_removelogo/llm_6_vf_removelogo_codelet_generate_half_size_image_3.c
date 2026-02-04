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
    uint8_t temp_val;
    for (y = 0; y < src_h / 2; y++) {
        for (x = 0; x < src_w / 2; x++) {
            int src_idx_base = (y << 1) * src_linesize;
            int dst_idx = y * dst_linesize + x;

            temp_val = src_data[src_idx_base + (x << 1)];
            temp_val |= src_data[src_idx_base + (x << 1) + 1];
            temp_val |= src_data[src_idx_base + src_linesize + (x << 1)];
            temp_val |= src_data[src_idx_base + src_linesize + (x << 1) + 1];

            dst_data[dst_idx] = temp_val;
            dst_data[dst_idx] = (1 > dst_data[dst_idx]) ? dst_data[dst_idx] : 1;
        }
    }
}
