#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int y;
int size;
uint16_t *src;
uint16_t *left;
int dc;

#define DATA_SIZE (64 * 1024 * 1024) // ~128MB of total data (adjustable)

static uint16_t src_data[DATA_SIZE];
static uint16_t left_data[DATA_SIZE];

void init_vars() {
    size = 8192; // Ensures loop runs enough iterations for ~0.01s
    stride = 8192;
    dc = 1234;

    src = src_data;
    left = left_data;

    for (int i = 0; i < size; i++) {
        left[i] = i * 3 + 1;
    }
    for (int i = 0; i < size * stride; i++) {
        src[i] = i * 2;
    }
}