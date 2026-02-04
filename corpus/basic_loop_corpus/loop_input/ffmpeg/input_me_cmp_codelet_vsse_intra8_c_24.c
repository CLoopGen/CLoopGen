#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *s;
ptrdiff_t stride;
int h;
int score;
int x;
int y;

static uint8_t *buffer;
static int buf_size;

void init_vars() {
    buf_size = 16777216; // 16 MB
    buffer = (uint8_t*)aligned_alloc(32, buf_size);
    if (!buffer) {
        exit(1);
    }

    for (int i = 0; i < buf_size; i++) {
        buffer[i] = rand() % 256;
    }

    stride = 256;
    h = 65536 / stride;
    s = buffer;
    score = 0;
    x = 0;
    y = 0;
}