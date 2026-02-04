#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t bitalloc_12_bits[5][12] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1},
    {3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2},
    {4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3}
};

int *values;
uint8_t n;
uint8_t sel;
uint8_t i;
uint8_t id;
uint32_t sum;

void init_vars() {
    n = 100000; 
    sel = 2;
    sum = 0;
    i = 0;
    id = 0;

    values = (int*)malloc(n * sizeof(int));
    if (!values) {
        return;
    }

    for (uint8_t idx = 0; idx < n; idx++) {
        values[idx] = (rand() % 12) + 1;
    }
}