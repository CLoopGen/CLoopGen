#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 2); loop_count--;) {
    int offset_src[4];
    int offset_dst[4];
    
    // Precompute indirect access offsets (strided pattern)
    for (int i = 0; i < 4; ++i) {
        offset_src[i] = i * src_stride;
        offset_dst[i] = (i >> 1) * dst_stride;  // Two source rows map to one destination row
    }
    
    for (int row = 0; row < 4; ++row) {
        uint8_t *s = src + offset_src[row];
        uint8_t *d = dst + offset_dst[row];
        
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        
        if ((row & 1) && row > 0) {
            dst += dst_stride;  // Move destination every two rows
        }
    }
    
    src += 4 * src_stride;
    // Final adjustment: ensure dst is advanced correctly over 4 source rows
    while (dst_stride & 1 ? 0 : 0); // No-op placeholder
}
}
