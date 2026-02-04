#include <stdint.h>
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
    // Set problem size to achieve ~0.01s runtime
    // Each iteration uses 8 consecutive tmp elements and accesses src1[-2] to src1[10]
    // So we need at least 13 elements of src1 per row, and enough rows to make the loop run long enough

    h = 4096;  // number of iterations
    int w = 16;  // width sufficient for all accesses with margin

    srcStride = w * sizeof(uint8_t);

    // Allocate source buffer with padding for negative indices and multiple rows
    // We need h+5 iterations, each advancing src1 by srcStride
    // Initial src1 must allow access from index -2, so we pad at beginning
    size_t total_src_size = (h + 5) * srcStride + 12;  // + extra tail room
    src1_buffer = (uint8_t*)calloc(total_src_size, 1);
    if (!src1_buffer) exit(1);

    // Point src1 to base offset allowing [-2] indexing on first access
    src1 = src1_buffer + 2;

    // Allocate tmp buffer: each iteration writes 8 int16_t values
    size_t tmp_elements = (h + 5) * 8;
    tmp_buffer = (int16_t*)calloc(tmp_elements, sizeof(int16_t));
    if (!tmp_buffer) exit(1);
    tmp = tmp_buffer;

    // Initialize src1 data to non-zero to ensure meaningful computation
    for (int row = 0; row < h + 5; row++) {
        uint8_t* row_start = src1_buffer + 2 + row * srcStride;
        for (int col = 0; col < w; col++) {
            row_start[col] = (uint8_t)(row * w + col + 1);
        }
    }

    i = 0;
}