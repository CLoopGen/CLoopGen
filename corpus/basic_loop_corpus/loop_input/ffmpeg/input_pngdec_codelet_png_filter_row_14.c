#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int size;
int i;
int r;
int g;
int b;
int a;

void init_vars() {
    // Set data size to achieve approximately 0.01 seconds runtime
    // Based on typical performance, 64MB gives reasonable timing for this kind of loop
    size = 64 * 1024 * 1024;  // 64 MB

    // Allocate memory for arrays
    dst = (uint8_t*)aligned_alloc(32, size);
    src = (uint8_t*)aligned_alloc(32, size);
    last = (uint8_t*)aligned_alloc(32, size);

    // Initialize arrays with non-zero values for realistic computation
    srand((unsigned int)time(NULL));
    for (int j = 0; j < size; ++j) {
        src[j] = rand() & 255;
        last[j] = rand() & 255;
    }

    // Initialize scalar variables
    i = 0;
    r = rand() & 255;
    g = rand() & 255;
    b = rand() & 255;
    a = rand() & 255;
}