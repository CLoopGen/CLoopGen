#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern int height;
extern int linesize;
extern int x;
extern int y;
extern int i;
extern int size;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using an index array (simulated via arithmetic)
    // Simulate indirect access pattern by using a strided step over rows
    int stride = linesize / 4; // Convert byte stride to uint32_t stride
    int total_elements = width * height;
    int start_idx = y * width + x;
    for (i = 0; i < size; i++) {
        int linear_idx = start_idx + i;
        if (linear_idx >= total_elements) break;
        int row = linear_idx / width;
        int col = linear_idx % width;
        uint32_t *addr = (uint32_t*)(dst + row * linesize + col * 4);
        *addr = pixel;
    }
}
