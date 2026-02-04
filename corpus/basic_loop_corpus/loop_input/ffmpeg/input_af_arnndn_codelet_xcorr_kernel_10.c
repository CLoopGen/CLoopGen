#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
float *y;
float sum[4];
int len;
float y_0;
float y_1;
float y_2;
float y_3;
int j;

static float *x_buf;
static float *y_buf;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total float data (64M floats)
    len = data_size / sizeof(float) / 2; // Two arrays: x and y
    len = (len / 4) * 4; // Ensure divisible by 4 for loop unrolling

    x_buf = aligned_alloc(32, len * sizeof(float));
    y_buf = aligned_alloc(32, (len + 3) * sizeof(float)); // Extra space to avoid out-of-bounds

    if (!x_buf || !y_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    x = x_buf;
    y = y_buf;

    for (int i = 0; i < len; ++i) {
        x_buf[i] = 1.0f + (i % 100) * 0.01f;
        y_buf[i] = 2.0f + (i % 100) * 0.02f;
    }

    // Initialize y_0, y_1, y_2, y_3 from first four elements of y
    y_0 = y_buf[0];
    y_1 = y_buf[1];
    y_2 = y_buf[2];
    y_3 = y_buf[3];

    // Initialize sum array
    sum[0] = 0.0f;
    sum[1] = 0.0f;
    sum[2] = 0.0f;
    sum[3] = 0.0f;

    j = 0;
}