#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
int stride;
int y;
uint8_t *p;
int s[10];
int QP2;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime
    const int block_height = 16;
    const int block_width = 16;
    
    stride = block_width + 2; // Add padding to prevent out-of-bounds access
    src = (uint8_t*)aligned_alloc(32, total_size);
    if (!src) exit(1);

    // Initialize src with non-zero values to ensure meaningful computation
    for (size_t i = 0; i < total_size; i++) {
        src[i] = (uint8_t)(i % 255 + 1);
    }

    // Ensure safe initialization of s array
    for (int i = 0; i < 10; i++) {
        s[i] = (i > 0) ? (1 << (i % 8)) : 0;
    }

    // Initialize QP2 to a reasonable value within typical quantization range
    QP2 = 3;

    // Initialize p to NULL; it will be set in the loop
    p = NULL;
}