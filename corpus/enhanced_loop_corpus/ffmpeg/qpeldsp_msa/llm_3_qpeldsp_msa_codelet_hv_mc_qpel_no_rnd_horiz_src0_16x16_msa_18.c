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
// Change to strided memory access: process every other row in a staggered pattern
for (loop_count = (height >> 3); loop_count--;) {
    // Access rows with stride doubling (strided access over source and destination)
    uint8_t *s[8];
    uint8_t *d[8];
    
    for (int i = 0; i < 8; ++i) {
        s[i] = src + (i * 2 * src_stride);  // Stride of 2 in source
        d[i] = dst + (i * 2 * dst_stride);  // Stride of 2 in destination
    }

    // Perform dummy operations to simulate work
    for (int i = 0; i < 8; ++i) {
        d[i][0] = s[i][0];  // Example byte copy
    }

    // Advance pointers by 8 rows effectively due to doubled stride
    src += (16 * src_stride);
    dst += (16 * dst_stride);
}
}
