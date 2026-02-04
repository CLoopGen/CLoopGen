#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t src_buffer[134217728]; // 128 MB
static uint8_t dst_buffer[134217728]; // 128 MB

void init_vars() {
    size = 134217728; // 128 MB of input data
    dsize = 0;
    i = 0;

    for (int j = 0; j < size; j++) {
        src_buffer[j] = rand() % 5;
    }

    src = src_buffer;
    dst = dst_buffer;
}