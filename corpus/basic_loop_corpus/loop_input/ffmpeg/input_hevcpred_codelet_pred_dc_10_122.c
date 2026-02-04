#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int x;
int size;
uint16_t *src;
uint16_t *top;
int dc;

static uint16_t src_buffer[65536];
static uint16_t top_buffer[65536];

void init_vars() {
    size = 65536;
    stride = 1;
    dc = 123;
    src = src_buffer;
    top = top_buffer;
    for (int i = 0; i < size; i++) {
        top[i] = (uint16_t)(i * 7 + 42);
    }
}