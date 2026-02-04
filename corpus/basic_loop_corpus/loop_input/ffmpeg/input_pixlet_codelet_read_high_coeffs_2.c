#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int width;
ptrdiff_t stride;
unsigned int rlen;
unsigned int j;
unsigned int k;

static int16_t *dst_buffer;
static ptrdiff_t buffer_stride;

void init_vars() {
    width = 1024;
    rlen = 262144;
    j = 0;
    
    buffer_stride = width + 32;
    size_t total_size = buffer_stride * ((rlen + width - 1) / width);
    
    dst_buffer = aligned_alloc(32, total_size * sizeof(int16_t));
    
    if (!dst_buffer) {
        exit(1);
    }
    
    for (size_t i = 0; i < total_size; i++) {
        dst_buffer[i] = (int16_t)0xdead;
    }
    
    dst = dst_buffer;
    stride = buffer_stride;
}