#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

unsigned char *lum;
unsigned char *cb;
unsigned char *cr;
unsigned char *p;
int width;
int height;
int wrap;
int wrap3;
int x;
int y;
int r;
int g;
int b;
int r1;
int g1;
int b1;

void init_vars() {
    width = 1024;
    height = 512;
    wrap = 1024;
    wrap3 = width * 3;

    size_t lum_size = (size_t)wrap * height;
    size_t chroma_size = (size_t)(width / 2) * (height / 2);
    size_t rgb_size = (size_t)width * height * 3 + 32;

    lum = aligned_alloc(32, lum_size);
    cb = aligned_alloc(32, chroma_size);
    cr = aligned_alloc(32, chroma_size);
    p = aligned_alloc(32, rgb_size);

    memset(lum, 0, lum_size);
    memset(cb, 128, chroma_size);
    memset(cr, 128, chroma_size);

    for (size_t i = 0; i < rgb_size; i++) {
        p[i] = rand() % 256;
    }

    x = 0;
    y = 0;
    r = 0;
    g = 0;
    b = 0;
    r1 = 0;
    g1 = 0;
    b1 = 0;
}