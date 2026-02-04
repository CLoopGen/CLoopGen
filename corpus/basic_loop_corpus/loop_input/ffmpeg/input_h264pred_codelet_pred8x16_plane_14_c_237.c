#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 1024;
uint16_t *src0;
uint16_t *src1;
uint16_t *src2;
int H = 0;
int V = 0;

#define DATA_SIZE (64 << 20)  // 64 MB of data
static uint16_t *data_buffer;

void init_vars() {
    data_buffer = (uint16_t*)aligned_alloc(32, DATA_SIZE);
    if (!data_buffer) {
        exit(1);
    }

    src0 = data_buffer + 4;  // Offset to allow -k and +k access with k up to 4
    src1 = data_buffer + 8192;
    src2 = data_buffer + 16384;

    for (size_t i = 0; i < DATA_SIZE / sizeof(uint16_t); ++i) {
        data_buffer[i] = rand() & 0xFFFF;
    }
}