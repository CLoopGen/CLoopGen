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

#define DATA_SIZE (128 << 20)  // 128 MB total data size
static uint8_t buffer[DATA_SIZE];

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 26;
    C = 37;
    D = 48;

    // Set image height and stride
    h = 4096;
    stride = 16384;  // Ensures we can access src[stride + 1] safely

    // Ensure dimensions are compatible with buffer size
    // Total required memory: h * stride for both src and dst (plus padding)
    size_t required_size = 2 * h * stride;
    if (required_size > DATA_SIZE) {
        fprintf(stderr, "Error: Required memory exceeds buffer size\n");
        exit(1);
    }

    // Align base pointers to stride boundaries
    src = buffer;
    dst = buffer + h * stride;

    // Initialize source data to avoid undefined behavior
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < stride; x++) {
            src[y * stride + x] = rand() & 0xFF;
            dst[y * stride + x] = rand() & 0xFF;
        }
    }

    // Initialize loop index
    i = 0;
}