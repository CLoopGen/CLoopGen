#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data[4];
extern int linesize[4];
extern int width;
extern int height;
extern int frame_index;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute memory indices into an auxiliary array and access data indirectly
    // Simulates scenarios with non-regular or gathered access patterns
    int total_elements = width * height;
    int *indices = (int*)malloc(total_elements * sizeof(int));
    if (!indices) return; // Handle allocation failure

    int idx = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            indices[idx++] = y * linesize[0] + x;
        }
    }

    // Now use indirect access through the index array
    for (idx = 0; idx < total_elements; idx++) {
        int linear_x = idx % width;
        int linear_y = idx / width;
        data[0][indices[idx]] = linear_x + linear_y + frame_index * 3;
    }

    free(indices);
}
