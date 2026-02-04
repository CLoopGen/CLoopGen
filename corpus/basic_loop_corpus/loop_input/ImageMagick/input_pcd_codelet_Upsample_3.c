#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t width = 1024;
size_t height = 1024;
size_t scaled_width = 2048;

unsigned char *pixels;

ssize_t x;
ssize_t y;

unsigned char *p;
unsigned char *q;
unsigned char *r;

void init_vars() {
    pixels = (unsigned char*)calloc(scaled_width * height * 2, sizeof(unsigned char));
    if (!pixels) {
        exit(1);
    }

    for (size_t i = 0; i < scaled_width * height * 2; i++) {
        pixels[i] = (unsigned char)(i % 251);
    }
}