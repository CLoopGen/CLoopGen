#include <stdlib.h>
#include <stddef.h>

float *block;
int width;
int height;
int stride;
float mean;

static float *block_data;
static int block_size;

void init_vars() {
    width = 1024;
    height = 512;
    stride = 1024;
    mean = 0.0f;
    
    block_size = stride * height;
    block_data = aligned_alloc(32, block_size * sizeof(float));
    
    if (!block_data) exit(1);
    
    for (int i = 0; i < block_size; i++) {
        block_data[i] = (float)((rand() % 2000) - 1000) / 1000.0f;
    }
    
    block = block_data;
}