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

static unsigned char *lum_data;
static unsigned char *cb_data;
static unsigned char *cr_data;
static unsigned char *p_data;

void init_vars() {
    const size_t lum_size = (size_t)width * height;
    const size_t chroma_size = ((size_t)width / 2) * (height / 2);
    const size_t p_size = (size_t)width * height * 3;

    lum_data = aligned_alloc(32, lum_size);
    cb_data = aligned_alloc(32, chroma_size);
    cr_data = aligned_alloc(32, chroma_size);
    p_data = aligned_alloc(32, p_size);

    lum = lum_data;
    cb = cb_data;
    cr = cr_data;
    p = p_data;

    for (size_t i = 0; i < p_size; ++i) {
        p_data[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < lum_size; ++i) {
        lum_data[i] = 0;
    }
    for (size_t i = 0; i < chroma_size; ++i) {
        cb_data[i] = 128;
        cr_data[i] = 128;
    }
}