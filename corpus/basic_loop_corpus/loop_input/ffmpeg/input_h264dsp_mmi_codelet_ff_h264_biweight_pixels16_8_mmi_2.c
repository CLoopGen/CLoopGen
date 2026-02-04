#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int height;
int y;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    height = 1024;
    stride = 1024;
    size_t total_size = (size_t)height * (size_t)stride;

    src_buffer = malloc(total_size);
    dst_buffer = malloc(total_size);

    if (!src_buffer || !dst_buffer) {
        free(src_buffer);
        free(dst_buffer);
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;
}