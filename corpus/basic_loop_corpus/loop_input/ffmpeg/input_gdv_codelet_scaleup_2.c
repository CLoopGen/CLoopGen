#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *dst;
uint8_t *src;
int w;
int x;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t data_size;

void init_vars() {
    struct timeval start, end;
    double elapsed;
    
    data_size = 128 * 1024 * 1024; // 128 MB
    
    src_buffer = (uint8_t*)aligned_alloc(32, data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size);
    
    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    
    memset(dst_buffer, 0, data_size);
    
    src = src_buffer;
    dst = dst_buffer;
    w = data_size;
    x = 0;
}