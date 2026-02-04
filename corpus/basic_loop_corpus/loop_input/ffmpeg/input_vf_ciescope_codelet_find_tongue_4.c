#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t * pixels;
int w;
int linesize;
int row;
int i;

void init_vars() {
    w = 65536; 
    linesize = w * 4;
    row = 0;
    i = 0;

    pixels = aligned_alloc(32, (size_t)(linesize + 16) * sizeof(uint16_t));
    if (!pixels) exit(1);

    for (int j = 0; j < w; j++) {
        pixels[row * linesize + j * 4 + 0] = 0;
        pixels[row * linesize + j * 4 + 1] = 0;
        pixels[row * linesize + j * 4 + 2] = 0;
        pixels[row * linesize + j * 4 + 3] = 0;
    }

    pixels[row * linesize + w * 4] = 1;
}