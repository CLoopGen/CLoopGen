#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (128 << 20) // 128 MB total data size target

void init_vars() {
    // Set constants
    A = 10;
    B = 20;
    C = 30;
    D = 40;

    // Set image height and stride
    h = 4096;
    int width = 4;
    stride = width + 1; // Ensure we can access [stride + x] safely

    // Allocate large buffers to meet runtime target
    size_t buf_size = (size_t)h * (size_t)stride * sizeof(uint8_t);
    if (buf_size < DATA_SIZE) {
        // Scale up h to ensure sufficient data size
        h = DATA_SIZE / (stride * sizeof(uint8_t));
        buf_size = (size_t)h * (size_t)stride * sizeof(uint8_t);
    }

    // Recompute buffer size after adjusting h
    buf_size = (size_t)h * (size_t)stride * sizeof(uint8_t);

    // Allocate zero-initialized memory to avoid undefined behavior
    src = calloc(buf_size, 1);
    dst = calloc(buf_size, 1);

    // Initialize src with non-zero pattern to make computation meaningful
    for (size_t idx = 0; idx < buf_size; idx++) {
        src[idx] = (uint8_t)(idx % 251);
    }
}