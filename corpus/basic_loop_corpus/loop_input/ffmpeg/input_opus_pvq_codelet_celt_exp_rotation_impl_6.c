#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint32_t len;
uint32_t stride;
float c;
float s;
float *Xptr;
int i;

static float *Xptr_buffer = NULL;

void init_vars() {
    // Set parameters for ~0.01 sec runtime on modern CPU
    // Assuming moderate memory bandwidth and simple arithmetic
    // Aim for around 64M to 128M floats (~256MB max) depending on stride

    stride = 16; // Reasonable stride to induce some locality
    len = (1 << 24) / sizeof(float); // ~16M elements, large enough for measurable time
    while (len <= 2 * stride) {
        len = len * 2;
    }

    c = 0.7071f; // Example cosine value
    s = 0.7071f; // Example sine value

    // Allocate buffer: we need at least len elements, but pointer moves backward
    // Xptr starts at &Xptr_buffer[len - 1] and decrements, accessing up to [stride]
    size_t total_elements_needed = len + stride;
    Xptr_buffer = (float*)aligned_alloc(32, total_elements_needed * sizeof(float));
    if (!Xptr_buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero values
    for (size_t idx = 0; idx < total_elements_needed; idx++) {
        Xptr_buffer[idx] = (float)(idx % 1000) * 0.001f;
    }

    // Set Xptr to point just past the valid segment so that after first -- it's correct
    // Loop logic: for (i = len - 2*stride - 1; i >= 0; i--)
    // So we access Xptr[0] and Xptr[stride], and decrement Xptr each time
    // Thus, initial Xptr should be at base + len - 1, but we need to ensure:
    //   final address: start from high addr and go down to base+?
    // We require: initial Xptr must allow access to [stride] at every iteration
    // At last iteration: i=0, we access Xptr[0] and Xptr[stride], then do Xptr--
    // But no further use, so as long as Xptr >= base + len - 1 - (len - 2*stride - 1)? Let's reframe.

    // Number of iterations: len - 2*stride
    // Xptr decrements once per iteration -> total decrement: len - 2*stride
    // Final Xptr value: initial_Xptr - (len - 2*stride)
    // We require final_Xptr[stride] to be in bounds -> final_Xptr >= base, and final_Xptr + stride < base + total
    // => initial_Xptr - (len - 2*stride) + stride < base + total
    // => initial_Xptr < base + total - stride + (len - 2*stride) = base + total + len - 3*stride
    // Instead, simpler: let base = Xptr_buffer
    // Set Xptr = base + (len - 1)
    // Then during loop, index goes from (len-1) down to (len-1) - (len-2*stride-1) = 2*stride
    // So Xptr takes values: base+len-1, base+len-2, ..., base+2*stride
    // Then Xptr[0] is safe as long as base+2*stride >= base -> ok
    // Xptr[stride] accesses base+2*stride+stride = base+3*stride, which must be < base+total_elements_needed
    // So we require: 3*stride < total_elements_needed -> we allocated len+stride, so need len+stride > 3*stride -> len > 2*stride -> ensured above

    Xptr = Xptr_buffer + (len - 1);

    i = len - 2 * stride - 1; // Initial value used in loop condition
}