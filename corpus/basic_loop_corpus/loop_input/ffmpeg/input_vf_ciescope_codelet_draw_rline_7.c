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
int dx;
int sx;
int dy;
int sy;
int err;
int e2;

#define y0 _usr_y0
#define y1 _usr_y1

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB of data
    pixels = (uint16_t*)aligned_alloc(32, total_size);
    if (!pixels) exit(1);

    linesize = 1024; 
    x0 = 100;
    y0 = 100;
    x1 = 200;
    y1 = 150;

    dx = abs(x1 - x0);
    sx = (x0 < x1) ? 1 : -1;
    dy = abs(y1 - y0);
    sy = (y0 < y1) ? 1 : -1;
    err = dx - dy;

    e2 = 0;
}