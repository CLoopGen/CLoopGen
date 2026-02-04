#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int16_t *ptr;

static int16_t *data_buffer;
static size_t data_size;
static size_t num_iterations;

void init_vars() {
    data_size = 16 * 1024 * 1024; // 16 MB of data
    data_buffer = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    
    if (!data_buffer) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size; idx++) {
        data_buffer[idx] = (int16_t)(rand() % 512 - 256);
    }
    
    ptr = data_buffer;
    i = 0;
    num_iterations = data_size / 8;
}

__attribute__((destructor))
static void cleanup() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}