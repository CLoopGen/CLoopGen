#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width;
int i;
int32_t *dst;
int32_t *b0;
int32_t *b1;
int32_t *b2;
int32_t *b3;
int32_t *b4;
int32_t *b5;
int32_t *b6;
int32_t *b7;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; 
    const size_t num_elements = data_size / sizeof(int32_t);

    width = (int)num_elements;

    dst = (int32_t*)aligned_alloc(32, data_size);
    b0  = (int32_t*)aligned_alloc(32, data_size);
    b1  = (int32_t*)aligned_alloc(32, data_size);
    b2  = (int32_t*)aligned_alloc(32, data_size);
    b3  = (int32_t*)aligned_alloc(32, data_size);
    b4  = (int32_t*)aligned_alloc(32, data_size);
    b5  = (int32_t*)aligned_alloc(32, data_size);
    b6  = (int32_t*)aligned_alloc(32, data_size);
    b7  = (int32_t*)aligned_alloc(32, data_size);

    if (!dst || !b0 || !b1 || !b2 || !b3 || !b4 || !b5 || !b6 || !b7) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    srand(1);
    for (size_t idx = 0; idx < num_elements; ++idx) {
        dst[idx] = rand() % 256;
        b0[idx]  = rand() % 256;
        b1[idx]  = rand() % 256;
        b2[idx]  = rand() % 256;
        b3[idx]  = rand() % 256;
        b4[idx]  = rand() % 256;
        b5[idx]  = rand() % 256;
        b6[idx]  = rand() % 256;
        b7[idx]  = rand() % 256;
    }
}