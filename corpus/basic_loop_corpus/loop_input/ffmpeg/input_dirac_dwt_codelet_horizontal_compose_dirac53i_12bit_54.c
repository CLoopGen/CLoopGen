#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int w2 = 16384;
int32_t *b;
int32_t *temp;

void init_vars() {
    const size_t data_size = (size_t)w2 * 2;
    b = aligned_alloc(32, data_size * sizeof(int32_t));
    temp = aligned_alloc(32, data_size * sizeof(int32_t));

    for (size_t i = 0; i < data_size; i++) {
        b[i] = rand() % 1000;
        temp[i] = 0;
    }
}