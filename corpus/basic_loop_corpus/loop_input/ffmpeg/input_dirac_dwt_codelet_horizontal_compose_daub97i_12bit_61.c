#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2;
int x;
int b0;
int b1;
int b2;
int32_t *b;
int32_t *temp;

void init_vars() {
    w2 = 8192;
    size_t temp_size = w2 * 2;
    size_t b_size = w2 * 2;

    temp = (int32_t*)aligned_alloc(32, temp_size * sizeof(int32_t));
    b = (int32_t*)aligned_alloc(32, b_size * sizeof(int32_t));

    for (size_t i = 0; i < temp_size; i++) {
        temp[i] = rand() & 0xFFFFF;
    }

    for (size_t i = 0; i < b_size; i++) {
        b[i] = 0;
    }

    x = 0;
    b0 = rand() & 0xFFFFF;
    b1 = 0;
    b2 = 0;
}