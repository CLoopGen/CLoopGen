#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *lum;
unsigned char *cb;
unsigned char *cr;
unsigned char *p;

int width = 1920;
int height = 1080;
int wrap = 1920;
int wrap3 = 1920 * 3;
int x;
int y;
int r;
int g;
int b;
int r1;
int g1;
int b1;

void init_vars() {
    lum = aligned_alloc(32, (size_t)(height + 4) * wrap + 64);
    cb = aligned_alloc(32, (size_t)((height / 2) + 4) * (width / 2) + 64);
    cr = aligned_alloc(32, (size_t)((height / 2) + 4) * (width / 2) + 64);
    p = aligned_alloc(32, (size_t)(height + 4) * wrap3 + 64);

    for (int i = 0; i < (height + 4) * wrap; ++i) lum[i] = i & 0xFF;
    for (int i = 0; i < ((height / 2) + 4) * (width / 2); ++i) {
        cb[i] = 128;
        cr[i] = 128;
    }
    for (int i = 0; i < (height + 4) * wrap3; ++i) p[i] = rand() % 256;
}