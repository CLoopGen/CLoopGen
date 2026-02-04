#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int w2 = 10000;
int16_t *b;
int16_t *temp;

void init_vars() {
    size_t array_size = (size_t)w2 * 2;
    b = aligned_alloc(32, sizeof(int16_t) * array_size);
    temp = aligned_alloc(32, sizeof(int16_t) * array_size);

    for (size_t i = 0; i < array_size; i++) {
        b[i] = (int16_t)(i % 32767);
        temp[i] = 0;
    }
}