#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t * pixels;
int linesize;
int x0;
int _usr_y0;
int x1;
int _usr_y1;
uint16_t * rgbcolor;
int dx;
int sx;
int dy;
int sy;
int err;
int e2;

#define y0 _usr_y0
#define y1 _usr_y1

void init_vars() {
    const int width = 1024;
    const int height = 768;
    linesize = width * 4;
    size_t pixel_data_size = linesize * height * sizeof(uint16_t);
    pixels = (uint16_t*)aligned_alloc(32, pixel_data_size);
    for (size_t i = 0; i < pixel_data_size / sizeof(uint16_t); ++i) {
        pixels[i] = rand() % 65536;
    }

    rgbcolor = (uint16_t*)aligned_alloc(32, 4 * sizeof(uint16_t));
    rgbcolor[0] = 65535;
    rgbcolor[1] = 32768;
    rgbcolor[2] = 16384;
    rgbcolor[3] = 0;

    x0 = 100;
    y0 = 100;
    x1 = 800;
    y1 = 600;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = (x0 < x1) ? 1 : -1;
    sy = (y0 < y1) ? 1 : -1;
    err = dx - dy;
}