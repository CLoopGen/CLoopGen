#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_step;
uint8_t *src;
int src_step;
int len;
int radius;
int inv;
int x;
int sum;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    len = 65536;        
    radius = 16;        
    inv = 256;          
    x = 0;              
    sum = 0;            
    src_step = 1;       
    dst_step = 1;       

    size_t src_size = (len + 2 * radius + 1) * sizeof(uint8_t);
    size_t dst_size = len * sizeof(uint8_t);

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer + radius; 
    dst = dst_buffer;
}