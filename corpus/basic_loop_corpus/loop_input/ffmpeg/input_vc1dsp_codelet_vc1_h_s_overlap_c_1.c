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
    const size_t total_data_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime
    const size_t num_elements = total_data_size / sizeof(int16_t);
    
    // Allocate large enough arrays to avoid bounds issues given striding and loop count
    int16_t *left_base = calloc(num_elements, sizeof(int16_t));
    int16_t *right_base = calloc(num_elements, sizeof(int16_t));
    
    if (!left_base || !right_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Set valid strides (simulate row stride in 2D array, e.g., image processing)
    left_stride = 16;
    right_stride = 16;

    // Initialize left and right pointers to middle of allocated blocks to allow offset access
    // We need at least up to index 7 for left and 1 for right, so ensure room
    size_t offset = 8;
    left = left_base + offset;
    right = right_base + offset;

    // Initialize flag and randomization values
    flags = 1;  // Enable the conditional flip inside loop
    rnd1 = 3;
    rnd2 = 4;

    // Ensure initial memory locations accessed (left[6], left[7], right[0], right[1]) are valid
    for (int j = 0; j < 16; j++) {
        if (j < 8) left_base[offset + j] = j * 100;
        if (j < 8) right_base[offset + j] = j * 101;
    }
}