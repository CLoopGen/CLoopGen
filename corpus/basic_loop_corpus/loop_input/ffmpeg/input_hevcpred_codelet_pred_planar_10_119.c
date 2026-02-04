#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int trafo_size;
int x;
int y;
uint16_t *src;
uint16_t *top;
uint16_t *left;
int size;

#define DATA_SIZE_MB 4
#define MATRIX_SIDE (1 << 9) // 512, gives ~1MB per array

static uint16_t src_data[MATRIX_SIDE * MATRIX_SIDE];
static uint16_t top_data[MATRIX_SIDE + 1];
static uint16_t left_data[MATRIX_SIDE + 1];

void init_vars() {
    size = MATRIX_SIDE;
    stride = MATRIX_SIDE;
    trafo_size = 2; 

    src = src_data;
    top = top_data;
    left = left_data;

    for (int i = 0; i < size; i++) {
        left[i] = i & 0x3FF;
        top[i] = (i * 7) & 0x3FF;
    }
    left[size] = 512;
    top[size] = 256;

    for (int i = 0; i < size * size; i++) {
        src_data[i] = 0;
    }
}