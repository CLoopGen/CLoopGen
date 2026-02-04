#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
uint8_t *left;
int i;
uint8_t v[94];

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t top_data[DATA_SIZE];
static uint8_t left_data[DATA_SIZE];

void init_vars() {
    top = top_data + 1; // Adjust so that top[i-1] at i=0 accesses valid memory
    left = left_data;

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        left_data[idx] = rand() & 0xFF;
        top_data[idx] = rand() & 0xFF;
    }

    for (int j = 0; j < 94; j++) {
        v[j] = 0;
    }
}