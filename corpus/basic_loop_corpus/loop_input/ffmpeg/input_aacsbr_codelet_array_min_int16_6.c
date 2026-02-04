#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *array;
int nel = 131072; // 256KB of data (131072 elements * 2 bytes)
int i;
int min;

void init_vars() {
    array = (int16_t*)aligned_alloc(_Alignof(int16_t), nel * sizeof(int16_t));
    if (!array) {
        exit(1);
    }
    for (int j = 0; j < nel; j++) {
        array[j] = (int16_t)(rand() % 50000 - 25000);
    }
    i = 0;
    min = array[0];
}