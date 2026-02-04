#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h;
int i;

static uint8_t *src1_buffer;
static int16_t *tmp_buffer;

void init_vars() {
    // Allocate approximately 64MB of input data to target ~0.01s runtime
    size_t total_size = 64 * 1024 * 1024;
    size_t element_size = sizeof(uint8_t);
    size_t num_elements = total_size / element_size;

    // Ensure h is large enough to dominate loop overhead but within bounds
    // Each iteration advances src1 by srcStride and uses up to src1[10]
    // We need at least (h+5) rows with width >= 13 to cover [-2..10] safely
    size_t row_width = 13;
    h = (int)(num_elements / row_width);
    if (h > 100000) h = 100000;  // Cap h to avoid excessive stack usage in tmp

    srcStride = (ptrdiff_t)row_width;
    size_t buffer_size = (h + 10) * row_width;  // Add margin for safety

    src1_buffer = calloc(buffer_size, sizeof(uint8_t));
    if (!src1_buffer) exit(1);

    // Initialize valid region around expected access range
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src1_buffer[idx] = (uint8_t)(idx % 251);
    }

    src1 = src1_buffer + 2;  // Start so that [-2] is valid

    // tmp needs 8 int16_t per iteration, h+5 iterations
    size_t tmp_elements = (h + 5) * 8;
    tmp_buffer = malloc(tmp_elements * sizeof(int16_t));
    if (!tmp_buffer) exit(1);

    tmp = tmp_buffer;
}