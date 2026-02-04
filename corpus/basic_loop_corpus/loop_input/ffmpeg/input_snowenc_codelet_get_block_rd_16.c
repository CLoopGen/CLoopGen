#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define y0 _usr_y0
#define y1 _usr_y1

uint8_t (*obmc_edged)[32];
int obmc_stride;
int ref_stride;
uint8_t *dst;
IDWTELEM *pred;
uint8_t *cur;
int sx;
int sy;
int x0;
int _usr_y0;
int x1;
int _usr_y1;
int x;
int y;

void init_vars() {
    const int height = 4096;
    const int width = 32;
    obmc_stride = width;
    ref_stride = width;
    sx = 0;
    sy = 0;
    x0 = 0;
    _usr_y0 = 0;
    x1 = width;
    _usr_y1 = height;

    obmc_edged = (uint8_t(*)[32])aligned_alloc(32, sizeof(uint8_t) * height * 32);
    dst = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * (sy + height) * ref_stride + sx + width);
    pred = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * height * obmc_stride);
    cur = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * height * ref_stride);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 32; j++) {
            obmc_edged[i][j] = (uint8_t)((i + j) & 0xFF);
        }
    }
    for (int i = 0; i < height * obmc_stride; i++) {
        pred[i] = (IDWTELEM)(rand() % 256 - 128);
    }
    for (int i = 0; i < height * ref_stride; i++) {
        cur[i] = (uint8_t)(rand() & 0xFF);
    }
}