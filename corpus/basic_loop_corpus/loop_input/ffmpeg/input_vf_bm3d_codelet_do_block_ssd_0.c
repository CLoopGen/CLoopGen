#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int src_stride;
uint8_t *srcp;
uint8_t *refp;
int block_size;
double dist;
int x;
int y;

#define DATA_SIZE_MB 64
#define BLOCK_SIZE 128

static uint8_t *src_data;
static uint8_t *ref_data;

void init_vars() {
    block_size = BLOCK_SIZE;
    src_stride = block_size;
    
    size_t total_bytes = (size_t)DATA_SIZE_MB * 1024 * 1024;
    size_t num_blocks = total_bytes / (block_size * block_size);
    size_t data_elements = num_blocks * block_size * block_size;
    
    src_data = (uint8_t*)aligned_alloc(32, data_elements * sizeof(uint8_t));
    ref_data = (uint8_t*)aligned_alloc(32, data_elements * sizeof(uint8_t));
    
    for (size_t i = 0; i < data_elements; i++) {
        src_data[i] = rand() % 256;
        ref_data[i] = rand() % 256;
    }
    
    srcp = src_data;
    refp = ref_data;
    dist = 0.0;
    x = 0;
    y = 0;
}