#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

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

static float *top_data = NULL;
static float *bottom_data = NULL;
static float *dst_data = NULL;

void init_vars() {
    // Set image dimensions to achieve ~100ms runtime
    // Empirical testing suggests around 1M pixels gives good timing
    width = 1024;
    height = 512;

    // Ensure line sizes are at least as big as width (could be larger for alignment)
    top_linesize = width;
    bottom_linesize = width;
    dst_linesize = width;

    opacity = 0.75;

    // Allocate memory for arrays
    size_t num_elements = width * height;
    size_t data_size = num_elements * sizeof(float);

    top_data = (float *)aligned_alloc(32, data_size);
    bottom_data = (float *)aligned_alloc(32, data_size);
    dst_data = (float *)aligned_alloc(32, data_size);

    if (!top_data || !bottom_data || !dst_data) {
        // Fallback: use malloc if aligned_alloc fails
        free(top_data); free(bottom_data); free(dst_data);
        top_data = (float *)malloc(data_size);
        bottom_data = (float *)malloc(data_size);
        dst_data = (float *)malloc(data_size);
    }

    // Initialize with valid floating-point values to avoid NaN/inf issues
    for (size_t idx = 0; idx < num_elements; ++idx) {
        top_data[idx] = (float)(rand() % 1000) / 1000.0f;  // 0.0 to 1.0
        bottom_data[idx] = (float)(rand() % 1000) / 1000.0f;
        dst_data[idx] = 0.0f;
    }

    // Set pointers to start of data
    top = top_data;
    bottom = bottom_data;
    dst = dst_data;
}

// Cleanup function to prevent memory leaks (not called here but implied usage)
void cleanup_vars() {
    free(top_data);
    free(bottom_data);
    free(dst_data);
}