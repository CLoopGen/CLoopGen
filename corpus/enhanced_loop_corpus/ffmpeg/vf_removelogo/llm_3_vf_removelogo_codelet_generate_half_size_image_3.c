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
    // Variant 2: Strided memory access with reversed loop order (column-major traversal)
    int src_stride = src_linesize;
    int dst_stride = dst_linesize;
    
    // Transpose iteration order: iterate over x first, then y (strided access on outer loop)
    for (x = 0; x < src_w / 2; x++) {
        for (y = 0; y < src_h / 2; y++) {
            int src_x_offset = x << 1;
            int src_y_offset_0 = (y << 1) * src_stride;
            int src_y_offset_1 = src_y_offset_0 + src_stride;

            uint8_t val = src_data[src_y_offset_0 + src_x_offset] || 
                          src_data[src_y_offset_0 + src_x_offset + 1] ||
                          src_data[src_y_offset_1 + src_x_offset] || 
                          src_data[src_y_offset_1 + src_x_offset + 1];

            dst_data[y * dst_stride + x] = (1 > val) ? val : 1;
        }
    }
}
