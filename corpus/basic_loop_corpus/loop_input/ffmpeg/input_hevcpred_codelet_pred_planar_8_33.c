#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int trafo_size;
int x;
int y;
uint8_t *src;
uint8_t *top;
uint8_t *left;
int size;

#define DATA_SIZE_MB 64
#define MATRIX_BYTES (DATA_SIZE_MB * 1024ULL * 1024ULL)
#define MAX_SIZE (MATRIX_BYTES / sizeof(uint8_t))

static uint8_t src_buf[MATRIX_BYTES];
static uint8_t top_buf[MAX_SIZE + 1];
static uint8_t left_buf[MAX_SIZE + 1];

void init_vars() {
    size = 8192;
    while ((size * size) > MAX_SIZE) {
        size -= 1;
    }
    stride = size;
    trafo_size = 2;

    src = src_buf;
    top = top_buf;
    left = left_buf;

    for (int i = 0; i <= size; i++) {
        top[i] = rand() & 0xFF;
        left[i] = rand() & 0xFF;
    }
    for (int i = 0; i < size * size; i++) {
        src_buf[i] = 0;
    }
}