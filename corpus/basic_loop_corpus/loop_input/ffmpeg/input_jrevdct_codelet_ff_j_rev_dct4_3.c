#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int32_t tmp0;
int32_t tmp1;
int32_t tmp2;
int32_t tmp3;
int32_t tmp10;
int32_t tmp11;
int32_t tmp12;
int32_t tmp13;
int32_t z1;
int32_t d0;
int32_t d2;
int32_t d4;
int32_t d6;
int16_t *dataptr;
int rowctr;

static int16_t *data_buffer = NULL;
static size_t total_data_size = 0;

void init_vars() {
    const size_t input_size_bytes = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    const size_t element_count = input_size_bytes / sizeof(int16_t);
    
    data_buffer = (int16_t*)aligned_alloc(32, input_size_bytes);
    if (!data_buffer) {
        exit(1);
    }
    total_data_size = element_count;

    memset(data_buffer, 0, input_size_bytes);

    for (size_t i = 0; i < element_count; i++) {
        data_buffer[i] = (int16_t)(i % 50000);
    }

    dataptr = data_buffer;
    rowctr = 4 - 1;
}