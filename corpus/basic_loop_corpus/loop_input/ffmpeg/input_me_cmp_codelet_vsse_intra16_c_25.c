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
static int buffer_size = 16 * 1024 * 1024; // 16 MB for ~0.01 sec runtime

void init_vars() {
    buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!buffer) exit(1);

    stride = 16;
    h = buffer_size / stride;
    s = buffer;
    score = 0;
    x = 0;
    y = 0;

    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = rand() % 256;
    }
}