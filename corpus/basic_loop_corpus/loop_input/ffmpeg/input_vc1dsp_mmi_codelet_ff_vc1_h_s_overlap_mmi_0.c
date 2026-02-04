#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *left;
int16_t *right;
int left_stride;
int right_stride;
int flags;
int i;
int a;
int b;
int c;
int d;
int d1;
int d2;
int rnd1;
int rnd2;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of int16_t data
    const size_t num_elements = total_size / sizeof(int16_t);

    // Allocate large enough arrays to prevent out-of-bounds access given loop logic
    int16_t *left_base = calloc(num_elements, sizeof(int16_t));
    int16_t *right_base = calloc(num_elements, sizeof(int16_t));

    // Set strides to reasonable row sizes (e.g., simulate 2D array rows of 64 elements)
    left_stride = 64;
    right_stride = 64;

    // Initialize left and right pointers to middle of allocated space to allow offsets like [7] and strides
    size_t offset = 8; // Ensure at least index 7 is valid
    left = left_base + offset;
    right = right_base + offset;

    // Initialize control variables
    flags = 1; // Ensures the conditional block runs
    rnd1 = 3;
    rnd2 = 4;

    // Ensure memory is initialized for safe access in loop
    for (int j = 0; j < 8; j++) {
        size_t idx = j * left_stride;
        left[idx + 6] = (j + 1) * 10;
        left[idx + 7] = (j + 1) * 10 + 1;
        right[idx + 0] = (j + 1) * 20;
        right[idx + 1] = (j + 1) * 20 + 1;
    }
}