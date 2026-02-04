#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride;
uint8_t * src0;
uint8_t * src1;
uint8_t * src2;
int H;
int V;

static uint8_t *buffer_src0;
static uint8_t *buffer_src1;
static uint8_t *buffer_src2;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)
    
    stride = 16; 
    
    buffer_src0 = (uint8_t*)aligned_alloc(32, data_size + 32);
    buffer_src1 = (uint8_t*)aligned_alloc(32, data_size + 32);
    buffer_src2 = (uint8_t*)aligned_alloc(32, data_size + 32);
    
    if (!buffer_src0 || !buffer_src1 || !buffer_src2) {
        exit(1);
    }
    
    src0 = buffer_src0 + 16;
    src1 = buffer_src1 + 16 + 2 * stride;
    src2 = buffer_src2 + 16 + 2 * stride;
    
    for (int i = 0; i < data_size; ++i) {
        buffer_src0[i] = rand() % 256;
        buffer_src1[i] = rand() % 256;
        buffer_src2[i] = rand() % 256;
    }
    
    H = 0;
    V = 0;
}