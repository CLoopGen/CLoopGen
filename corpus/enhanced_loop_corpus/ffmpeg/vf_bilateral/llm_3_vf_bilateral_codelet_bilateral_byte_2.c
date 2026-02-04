#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int dst_linesize;
extern uint8_t *dst;
extern float *img_out_f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via step size
    int total_elements = width * height;
    int stride = 16; // Example stride to jump through data in larger steps (e.g., cache line oriented)
    int *indices = (int*)malloc(total_elements * sizeof(int));
    int idx = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            indices[idx++] = i * width + j;

    // Access elements with strided pattern across the index array
    for (int s = 0; s < stride; s++) {
        for (int k = s; k < total_elements; k += stride) {
            int linear_idx = indices[k];
            int i = linear_idx / width;
            int j = linear_idx % width;
            dst[j + i * dst_linesize] = (uint8_t)img_out_f[linear_idx];
        }
    }
    free(indices);
}
