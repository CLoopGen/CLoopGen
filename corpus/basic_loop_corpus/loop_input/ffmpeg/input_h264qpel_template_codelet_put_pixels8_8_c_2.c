#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *block;
uint8_t *pixels;
ptrdiff_t line_size;
int h;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

static uint8_t memory_pool[TOTAL_BYTES * 2] __attribute__((aligned(32)));
static uint8_t initialized = 0;

void init_vars() {
    if (initialized) return;
    
    line_size = 1920; 
    h = 1080;
    
    size_t required_memory = line_size * h * 2;
    if (required_memory > TOTAL_BYTES * 2) {
        fprintf(stderr, "Error: Not enough memory allocated\n");
        exit(1);
    }
    
    block = memory_pool;
    pixels = memory_pool + (line_size * h);
    
    for (size_t idx = 0; idx < line_size * h; idx++) {
        pixels[idx] = (uint8_t)(idx & 0xFF);
        block[idx] = 0;
    }
    
    initialized = 1;
}