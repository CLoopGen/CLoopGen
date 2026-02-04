#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;
uint8_t invert;
uint8_t *planep;
int width;
int height;
int stride;

static uint8_t *buffer;

void init_vars() {
    width = 4096;
    height = 4096;
    stride = width;
    invert = 0xAA;
    buffer = (uint8_t*)calloc(height, stride);
    if (!buffer) {
        exit(1);
    }
    planep = buffer;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            buffer[i * stride + j] = rand() & 0xFF;
        }
    }
}