#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int i;
int bias;
int E;
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static size_t total_size;

void init_vars() {
    total_size = 64 * 1024 * 1024; // 64 MB for substantial computation (~tens of ms on modern CPU)

    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);
    src_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
        dst_buffer[idx] = rand() & 0xFF;
    }

    dst = dst_buffer;
    src = src_buffer;

    stride = 8; 
    step = 8;   
    h = total_size / stride; 

    A = 15;    
    E = 17;    
    bias = 32; 

    i = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
    free(src_buffer);
}