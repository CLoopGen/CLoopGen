#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1_base;
uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp_base;
int16_t *tmp;
int h = 32768;
int i;

void init_vars() {
    const int width = 16;
    srcStride = width;
    
    int total_height = h + 5;
    size_t src_size = (total_height + 10) * srcStride;
    src1_base = (uint8_t*)aligned_alloc(32, src_size);
    if (!src1_base) exit(1);
    for (size_t i = 0; i < src_size; i++) {
        src1_base[i] = rand() % 256;
    }
    
    size_t tmp_size = (h + 5) * 8 * sizeof(int16_t);
    tmp_base = (int16_t*)aligned_alloc(32, tmp_size);
    if (!tmp_base) exit(1);
    
    src1 = src1_base + 2; 
    tmp = tmp_base;
}