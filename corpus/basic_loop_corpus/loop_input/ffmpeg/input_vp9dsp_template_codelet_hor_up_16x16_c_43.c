#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *left;
int i;
uint8_t v[30];

static uint8_t left_data[16] = {0};

void init_vars() {
    for (size_t j = 0; j < sizeof(left_data); j++) {
        left_data[j] = (uint8_t)(j * j + 3);
    }
    left = left_data;
}