#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;

#define DATA_SIZE (64 * 1024 * sizeof(uint16_t))
static uint16_t dst_data[64 * 1024];
static uint16_t src_data[64 * 1024];

void init_vars() {
    // Initialize scalar variables
    A = 42;
    h = 64 * 1024;
    stride = 1; // process elements sequentially

    // Initialize pointers to point into our static arrays
    dst = dst_data;
    src = src_data;

    // Initialize input data to avoid undefined behavior
    for (int j = 0; j < h; j++) {
        dst_data[j] = j % 1000;
        src_data[j] = (j * 3) % 800;
    }
}