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
    // Variant 1: Consecutive memory access with linear indexing and precomputed strides
    int src_stride = src_linesize;
    int dst_stride = dst_linesize;
    uint8_t *src_base = src_data;
    uint8_t *dst_base = dst_data;
    
    for (y = 0; y < src_h / 2; y++) {
        int src_row_start_0 = (y << 1) * src_stride;
        int src_row_start_1 = src_row_start_0 + src_stride;
        int dst_idx = y * dst_stride;
        for (x = 0; x < src_w / 2; x++) {
            int col_offset = x << 1;
            int src_idx_0 = src_row_start_0 + col_offset;
            int src_idx_1 = src_row_start_1 + col_offset;
            
            uint8_t val = src_base[src_idx_0] || src_base[src_idx_0 + 1] ||
                          src_base[src_idx_1] || src_base[src_idx_1 + 1];
            
            dst_base[dst_idx + x] = (1 > val) ? val : 1;
        }
    }
}
