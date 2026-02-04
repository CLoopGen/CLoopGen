#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_data_size = 16 * 1024 * 1024; // ~16MB for sufficient runtime

void init_vars() {
    src_buffer = (uint8_t*)calloc(total_data_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(total_data_size, sizeof(uint8_t));
    
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }
    
    for (size_t i = 0; i < total_data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
    
    src = src_buffer;
    dst = dst_buffer;
    stride = 8;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}