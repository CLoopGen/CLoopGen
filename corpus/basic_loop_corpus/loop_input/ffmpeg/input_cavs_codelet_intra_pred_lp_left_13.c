#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
uint8_t *left;
ptrdiff_t stride;
int x;
int y;

static uint8_t *d_buffer;
static uint8_t *left_buffer;

void init_vars() {
    const int height = 8;
    const int width = 8;
    stride = 16;
    
    d_buffer = aligned_alloc(32, stride * height);
    left_buffer = aligned_alloc(32, 10);

    d = d_buffer;
    left = left_buffer + 1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < stride; j++) {
            d_buffer[i * stride + j] = 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        left_buffer[i] = (i * i) % 256;
    }
}