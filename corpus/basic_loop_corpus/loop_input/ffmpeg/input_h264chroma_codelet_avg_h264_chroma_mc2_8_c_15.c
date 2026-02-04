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

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint8_t buffer[DATA_SIZE];

void init_vars() {
    // Initialize coefficients
    A = 15;
    B = 26;
    C = 37;
    D = 48;

    // Set image height and stride
    h = 4096;
    stride = 8192; // wide stride to simulate image rows

    // Ensure dimensions are valid for the loop's memory accesses:
    // We access src[0], src[1], src[2], src[stride+0], src[stride+1], src[stride+2]
    // So we need at least (h * stride) + stride + 3 bytes in src
    size_t required_size = (h + 1) * stride + 3;
    
    if (required_size > DATA_SIZE) {
        fprintf(stderr, "Error: required size %zu exceeds buffer size %d\n", required_size, DATA_SIZE);
        exit(1);
    }

    src = buffer;
    dst = buffer + ((h + 1) * stride); // place dst after src block

    // Initialize src and dst memory to avoid undefined behavior
    memset(src, 0x10, required_size);
    memset(dst, 0x20, h * stride);

    // Initialize loop index
    i = 0;
}