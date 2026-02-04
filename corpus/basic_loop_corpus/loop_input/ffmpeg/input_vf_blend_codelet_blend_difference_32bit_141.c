#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
float *top;
float *bottom;
float *dst;
double opacity;
int i;
int j;

static float *top_data;
static float *bottom_data;
static float *dst_data;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime
    // Each iteration does several float operations; aim for moderate size
    width = 2048;
    height = 256;
    
    // Ensure linesize accounts for padding or alignment (use width as base)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.5;

    // Allocate aligned memory to prevent access violations and simulate realistic image buffer layout
    size_t total_size = width * height * sizeof(float);
    
    top_data = aligned_alloc(32, total_size);
    bottom_data = aligned_alloc(32, total_size);
    dst_data = aligned_alloc(32, total_size);

    // Initialize pointers
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;

    // Initialize input data to avoid NaN or extreme values
    for (size_t idx = 0; idx < width * height; idx++) {
        top_data[idx] = (float)(rand() % 256) / 255.0f;
        bottom_data[idx] = (float)(rand() % 256) / 255.0f;
        dst_data[idx] = 0.0f;
    }
}

// Cleanup function to free allocated memory (not part of requirement but good practice)
void free_vars() {
    free(top_data);
    free(bottom_data);
    free(dst_data);
}