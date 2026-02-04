#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *s1;
uint8_t *s2;
ptrdiff_t stride;
int h = 1024;
int score;
int x;
int y;

static uint8_t *buffer1;
static uint8_t *buffer2;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB data size
    stride = 512;
    
    buffer1 = aligned_alloc(32, total_size + stride * h);
    buffer2 = aligned_alloc(32, total_size + stride * h);
    
    if (!buffer1 || !buffer2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_size + stride * h; i++) {
        buffer1[i] = rand() % 256;
        buffer2[i] = rand() % 256;
    }
    
    s1 = buffer1;
    s2 = buffer2;
    score = 0;
}