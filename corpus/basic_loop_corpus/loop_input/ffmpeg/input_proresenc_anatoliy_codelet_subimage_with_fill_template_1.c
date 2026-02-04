#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *src;
uint16_t *dst;
unsigned int dst_width;
int is_alpha_plane;
int box_width;
int i;
int j;
int src_stride;
int box_height;
uint16_t last_pix;

static uint16_t *src_buffer;
static uint16_t *dst_buffer;
static size_t total_data_size;

void init_vars() {
    // Aim for ~64MB of data to ensure loop runs about 0.01s on modern CPU
    const size_t target_bytes = 64 * 1024 * 1024;
    const size_t element_size = sizeof(uint16_t);
    
    // Assume average dimensions: make image width around 4096, adjust height accordingly
    dst_width = 4096;
    box_width = 64;  // Small box at start
    box_height = target_bytes / (element_size * dst_width);
    if (box_height < 1) box_height = 1;
    if (box_height > 16384) box_height = 16384;
    
    src_stride = dst_width + 16; // Add some padding to test stride
    
    is_alpha_plane = rand() % 2; // Randomly set for variation
    
    total_data_size = (size_t)box_height * src_stride;
    size_t dst_data_size = (size_t)box_height * dst_width;
    
    // Allocate aligned memory to avoid issues and improve performance
    src_buffer = aligned_alloc(64, total_data_size * element_size);
    dst_buffer = aligned_alloc(64, dst_data_size * element_size);
    
    // Initialize buffers with dummy data
    for (size_t idx = 0; idx < total_data_size; ++idx) {
        src_buffer[idx] = (uint16_t)(idx % 1024);
    }
    for (size_t idx = 0; idx < dst_data_size; ++idx) {
        dst_buffer[idx] = 0;
    }
    
    // Set pointers
    src = src_buffer;
    dst = dst_buffer;
    
    // Initialize scalar variables used in loop
    i = 0;
    j = 0;
    last_pix = 0x1234;
}