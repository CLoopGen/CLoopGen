#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (128 << 20) // 128 MB total data size target

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 25;
    C = 35;
    D = 45;

    // Set image-like parameters: assume a width of 1920 pixels, height derived from total size
    int width = 1920;
    stride = width;
    h = (DATA_SIZE / width); // Adjust height so total input size is about target
    if (h < 1) h = 1;
    if (h > 65536) h = 65536; // Cap to reasonable size

    // Ensure we don't overflow the array indexing in the loop:
    // src[stride + 2] requires at least (h+1)*stride + 3 bytes
    size_t required_src_size = (h + 1) * stride + 3;
    size_t required_dst_size = h * stride;

    src = (uint8_t*)aligned_alloc(32, required_src_size);
    dst = (uint8_t*)aligned_alloc(32, required_dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src with random data
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < required_src_size; ++idx) {
        src[idx] = rand() & 0xFF;
    }

    // Zero-initialize dst
    memset(dst, 0, required_dst_size);
}