#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t width = 1024;
size_t height = 512;
size_t scaled_width = 2048;

unsigned char *pixels;
ssize_t x;
ssize_t y;
unsigned char *p;
unsigned char *q;

void init_vars() {
    size_t total_size = scaled_width * height * 2;
    pixels = (unsigned char*)calloc(total_size, sizeof(unsigned char));
    if (!pixels) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        pixels[i] = rand() % 256;
    }
}