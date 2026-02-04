#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h;
int i;

static uint8_t *src1_buffer;
static int16_t *tmp_buffer;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // Aim for ~128MB of data
    const size_t element_size = sizeof(uint8_t);
    const size_t buffer_size = total_data_size / element_size;
    
    srcStride = 16; 
    h = (buffer_size - 10) / srcStride; 

    if (h <= 0) h = 1;

    src1_buffer = aligned_alloc(32, (h + 5) * srcStride * sizeof(uint8_t) + 20);
    tmp_buffer = aligned_alloc(32, (h + 5) * 8 * sizeof(int16_t));

    if (!src1_buffer || !tmp_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src1 = src1_buffer + 2; 
    tmp = tmp_buffer;

    for (size_t idx = 0; idx < (h + 5) * srcStride + 18; ++idx) {
        src1_buffer[idx] = (uint8_t)(idx % 256);
    }

    for (int idx = 0; idx < (h + 5) * 8; ++idx) {
        tmp_buffer[idx] = 0;
    }
}