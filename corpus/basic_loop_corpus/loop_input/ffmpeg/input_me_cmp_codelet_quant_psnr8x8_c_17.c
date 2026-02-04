#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t (*temp);
int16_t * bak;
int sum;
int i;

static const size_t num_elements = 64;

void init_vars() {
    temp = (int16_t*)aligned_alloc(_Alignof(int16_t), num_elements * sizeof(int16_t));
    bak = (int16_t*)aligned_alloc(_Alignof(int16_t), num_elements * sizeof(int16_t));

    for (size_t j = 0; j < num_elements; j++) {
        temp[j] = (int16_t)(j % 32);
        bak[j] = (int16_t)((j + 8) % 32);
    }

    sum = 0;
    i = 0;
}