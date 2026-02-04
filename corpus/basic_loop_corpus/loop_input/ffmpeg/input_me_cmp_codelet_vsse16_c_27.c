#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int h;
int score;
int x;
int y;

static uint8_t *buffer1;
static uint8_t *buffer2;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime
    const int block_width = 16;
    
    stride = block_width + 16; // Ensure stride is larger than 16 to avoid overlap
    h = total_size / stride / 2; // Adjust height so total access is within bounds
    if (h < 2) h = 2;

    size_t buffer_size = (h + 1) * stride * sizeof(uint8_t);

    buffer1 = aligned_alloc(32, buffer_size);
    buffer2 = aligned_alloc(32, buffer_size);

    if (!buffer1 || !buffer2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        buffer1[i] = rand() % 256;
        buffer2[i] = rand() % 256;
    }

    s1 = buffer1;
    s2 = buffer2;
    score = 0;
}