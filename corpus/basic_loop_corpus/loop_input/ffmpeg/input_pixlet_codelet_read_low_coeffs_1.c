#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int width;
ptrdiff_t stride;
unsigned int k;
unsigned int j;
int rlen;

static int16_t *dst_buffer;
static ptrdiff_t buffer_stride;

void init_vars() {
    width = 1024;
    rlen = 262144;
    j = 0;
    buffer_stride = width * sizeof(int16_t);
    dst_buffer = aligned_alloc(32, (rlen / width + 1) * buffer_stride);
    if (!dst_buffer) {
        exit(1);
    }
    dst = dst_buffer;
    stride = buffer_stride / sizeof(int16_t);
}