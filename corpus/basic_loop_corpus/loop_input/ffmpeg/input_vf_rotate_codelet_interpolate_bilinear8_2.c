#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst_color;
uint8_t *src;
int src_linesize;
int src_linestep;
int int_x;
int int_y;
int frac_x;
int frac_y;
int i;
int int_x1;
int int_y1;

static uint8_t *src_buffer = NULL;
static uint8_t *dst_buffer = NULL;

void init_vars() {
    // Set parameters to ensure valid memory access and reasonable runtime
    src_linestep = 64;                    // Number of iterations in loop
    src_linesize = 1024;                  // Line stride for 2D indexing
    int_x = 10;                           // Valid index within bounds
    int_y = 20;
    int_x1 = 11;                          // Must be <= src_linesize - int_x1*src_linestep - ... so keep small
    int_y1 = 21;
    frac_x = 32768;                       // Midpoint fraction (1<<16)/2
    frac_y = 32768;

    // Ensure that max index used: src_linestep * int_x1 + src_linesize * int_y1 + src_linestep
    // is within allocated bounds
    size_t max_src_offset = src_linestep * int_x1 + src_linesize * int_y1 + src_linestep;
    size_t dst_size = src_linestep;

    // Allocate buffers with proper size
    src_buffer = (uint8_t*)calloc(max_src_offset + 1, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(dst_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src with non-zero data to avoid undefined behavior in computation
    for (size_t idx = 0; idx < max_src_offset; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }

    // Assign pointers
    src = src_buffer;
    dst_color = dst_buffer;
}