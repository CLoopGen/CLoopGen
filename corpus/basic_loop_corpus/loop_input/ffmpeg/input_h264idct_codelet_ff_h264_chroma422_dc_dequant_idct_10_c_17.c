#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int stride;
int xStride;
int i;
unsigned int temp[8];
int32_t *block;

void init_vars() {
    // Set up parameters to control memory access within bounds
    xStride = 1;
    stride = 64 * 1024;  // Large stride to ensure sufficient data size

    // Allocate block with size based on maximum index used in loop
    // Maximum index: stride * 3 + xStride * 1 = 3*stride + 1
    size_t max_index = stride * 3 + xStride * 1;
    size_t num_elements = max_index + 1;
    
    // Aim for approximately 1MB - 256MB of data; adjust if needed
    size_t target_bytes = 16 * 1024 * 1024; // 16 MB
    size_t element_size = sizeof(int32_t);
    size_t required_elements = target_bytes / element_size;
    
    if (num_elements < required_elements) {
        num_elements = required_elements;
        // Adjust stride to meet size requirement while keeping loop valid
        stride = (num_elements - 1) / 4; // Ensure 4*i doesn't overflow
    }

    block = (int32_t*)aligned_alloc(32, num_elements * element_size);
    
    if (!block) {
        // Fallback: smaller allocation if large one fails
        num_elements = 1024 * 1024 / sizeof(int32_t);
        block = (int32_t*)calloc(num_elements, element_size);
    }

    // Initialize block with non-zero values to make computation meaningful
    for (size_t idx = 0; idx < num_elements; idx++) {
        block[idx] = (int32_t)(idx % 1000);
    }

    // Initialize temp array
    for (int j = 0; j < 8; j++) {
        temp[j] = j * 100;
    }
}