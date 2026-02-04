#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint8_t *src0;
uint8_t *src1;
uint8_t *src2;
int H;
int V;

static uint8_t *buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    
    buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    
    if (!buffer) {
        exit(1);
    }
    
    stride = 64;
    
    src0 = buffer + 8;
    
    src1 = buffer + 128;
    
    src2 = buffer + data_size - 128;
    
    H = 0;
    V = 0;
    
    for (size_t i = 0; i < data_size; ++i) {
        buffer[i] = rand() & 0xFF;
    }
}