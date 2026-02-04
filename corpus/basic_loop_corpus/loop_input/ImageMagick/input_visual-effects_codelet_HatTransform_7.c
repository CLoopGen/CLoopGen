#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

size_t stride;
size_t extent;
float *kernel;
float *restrict p;
float *restrict q;
float *restrict r;
ssize_t i;

static float *kernel_data;
static float *p_data;
static float *q_data;
static float *r_data;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // Aim for ~64MB of data
    const size_t element_size = sizeof(float);
    extent = total_size / (4 * element_size); // Divide by 4 streams: kernel, p, q, r

    if (extent == 0) extent = 1;

    stride = 1; // Basic contiguous access

    // Allocate buffers
    kernel_data = aligned_alloc(32, extent * element_size);
    p_data = aligned_alloc(32, (extent * stride + 1) * element_size);
    q_data = aligned_alloc(32, (extent * stride + 1) * element_size);
    r_data = aligned_alloc(32, (extent * stride + 1) * element_size);

    // Initialize pointers
    kernel = kernel_data;
    p = p_data;
    q = q_data;
    r = &r_data[extent * stride]; // r starts at the end and moves backward

    // Initialize input data
    for (size_t idx = 0; idx < extent; idx++) {
        p_data[idx * stride] = 1.0f + idx * 0.01f;
        q_data[idx * stride] = 2.0f + idx * 0.02f;
    }
    for (size_t idx = 0; idx <= extent * stride; idx++) {
        r_data[idx] = 3.0f + idx * 0.03f;
    }
    for (size_t idx = 0; idx < extent; idx++) {
        kernel_data[idx] = 0.0f;
    }

    i = 0;
}