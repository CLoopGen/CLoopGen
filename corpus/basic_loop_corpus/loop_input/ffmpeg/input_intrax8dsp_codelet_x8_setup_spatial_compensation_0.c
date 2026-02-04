#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
ptrdiff_t stride;
uint8_t *ptr;
int sum;
int i;
int min_pix;
int max_pix;
uint8_t c;

uint8_t *global_ptr_mem = NULL;
uint8_t *global_dst_mem = NULL;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data for consistent timing (~0.01 sec on modern CPU)

    // Allocate memory for ptr and dst with proper alignment and bounds
    global_ptr_mem = (uint8_t*)aligned_alloc(32, data_size);
    global_dst_mem = (uint8_t*)aligned_alloc(32, data_size);

    if (!global_ptr_mem || !global_dst_mem) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize memory to avoid undefined behavior
    memset(global_ptr_mem, 0x5A, data_size);
    memset(global_dst_mem, 0, data_size);

    // Set reasonable values for variables
    dst = global_dst_mem;
    ptr = global_ptr_mem + 1; // Ensure (ptr - 1) is valid
    stride = 1; // Default stride; can be adjusted
    sum = 0;
    min_pix = 255;
    max_pix = 0;
    c = 0;
    i = 7;
}