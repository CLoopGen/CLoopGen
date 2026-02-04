#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *array;
int nel = 131072; // 256KB of data (131072 elements * 2 bytes each)
int i;
int min;

void init_vars() {
    array = (int16_t*)aligned_alloc(32, nel * sizeof(int16_t));
    if (!array) {
        exit(1);
    }
    for (int j = 0; j < nel; j++) {
        array[j] = rand() % 65536 - 32768;
    }
    i = 0;
    min = array[0];
}