#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;
int E;
ptrdiff_t step;

void init_vars() {
    // Set constants
    A = 17;  // Arbitrary coefficient
    E = 31;  // Another arbitrary coefficient
    step = 4; // Step offset within src array

    // Define data size to target ~0.01 seconds runtime
    // Assume each iteration processes 2 elements and has moderate arithmetic
    // Aim for ~1-2 million iterations depending on CPU speed
    h = 1 << 18;  // 262,144 rows

    // Stride in units of uint16_t (simulate row stride in image-like data)
    stride = 1024;  // 2KB per row

    // Allocate source and destination arrays
    size_t total_elements = h * stride;
    src = aligned_alloc(32, total_elements * sizeof(uint16_t));
    dst = aligned_alloc(32, total_elements * sizeof(uint16_t));

    // Initialize arrays with non-zero values to make computation meaningful
    for (size_t idx = 0; idx < total_elements; idx++) {
        src[idx] = (uint16_t)(idx & 0x3FF);  // 0-1023 repeating pattern
        dst[idx] = (uint16_t)((idx + 512) & 0x3FF);
    }

    // Ensure that during loop execution:
    // - dst[i*stride + 0] and dst[i*stride + 1] are valid
    // - src[i*stride + 0], src[i*stride + 1], src[i*stride + step + 0], src[i*stride + step + 1] are valid
    // So we require: stride >= step + 2
    // Our step is 4, so as long as stride >= 6 we're safe — 1024 is more than enough.
}

// Explicitly do not include main()