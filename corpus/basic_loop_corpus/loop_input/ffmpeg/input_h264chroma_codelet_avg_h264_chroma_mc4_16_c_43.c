#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;
int E;
ptrdiff_t step;

#define DATA_SIZE (64 * 1024 * sizeof(uint16_t))
static uint16_t dst_buffer[DATA_SIZE / sizeof(uint16_t)];
static uint16_t src_buffer[DATA_SIZE / sizeof(uint16_t) * 2];

void init_vars() {
    const int elements_per_row = 4;
    const int rows = DATA_SIZE / (elements_per_row * sizeof(uint16_t));
    
    h = rows;
    stride = elements_per_row;
    step = elements_per_row;
    
    A = 13;
    E = 19;
    
    dst = dst_buffer;
    src = src_buffer;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements_per_row; j++) {
            dst[i * stride + j] = (uint16_t)(i + j);
            src[i * stride + j] = (uint16_t)((i * 7 + j * 11) % 1000);
            src[i * stride + j + step] = (uint16_t)((i * 13 + j * 17) % 1000);
        }
    }
}