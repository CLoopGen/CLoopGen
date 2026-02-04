#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024ULL * 1024)

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h = 8000;
int i;

static uint8_t src1_buffer[TOTAL_SIZE];
static int16_t tmp_buffer[TOTAL_SIZE / sizeof(uint8_t) * 2];

void init_vars() {
    const size_t min_src_offset = 2;
    const size_t max_src_offset = 10;
    const size_t tmp_elements_per_iter = 8;
    
    srcStride = 16;
    
    size_t required_src_size = (h + 5) * srcStride + max_src_offset + min_src_offset;
    if (required_src_size > TOTAL_SIZE) {
        required_src_size = TOTAL_SIZE - max_src_offset - min_src_offset;
        h = (required_src_size - max_src_offset - min_src_offset) / srcStride - 5;
    }
    
    src1 = src1_buffer + min_src_offset;
    tmp = tmp_buffer;
    
    for (size_t i = 0; i < required_src_size + max_src_offset + min_src_offset; ++i) {
        src1_buffer[i] = rand() & 0xFF;
    }
    
    memset(tmp_buffer, 0, sizeof(tmp_buffer));
}