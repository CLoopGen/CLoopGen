#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (256 * 1024 * 1024)

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

void init_vars() {
    stride = 64; // chosen to be power of two for alignment and valid access
    h = (DATA_SIZE / stride) / 2; // ensure we don't exceed buffer size, allow room for stride+4 access
    if (h > 1000000) h = 1000000; // cap h to reasonable bound based on data size

    // Allocate buffers with extra space for safe access: need up to [stride + 4]
    dst_buffer = (uint8_t*)aligned_alloc(64, DATA_SIZE);
    src_buffer = (uint8_t*)aligned_alloc(64, DATA_SIZE);

    // Initialize pointers
    dst = dst_buffer;
    src = src_buffer;

    // Initialize coefficients
    A = 17;
    B = 31;
    C = -15;
    D = 9;

    // Ensure all memory accesses in loop are valid:
    // We require src[stride + 4] -> max index = (h-1)*stride + stride + 4 = h*stride + 4
    // So allocated size must be >= h*stride + 4. Our DATA_SIZE is large enough.

    // Initialize arrays to prevent undefined behavior
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        dst_buffer[idx] = (uint8_t)(idx % 256);
        src_buffer[idx] = (uint8_t)((idx * 7) % 256);
    }
}