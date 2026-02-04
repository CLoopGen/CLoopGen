#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *data[4];
int linesize[4];
int width;
int height;
int frame_index;
int x;
int y;

void init_vars() {
    width = 2048;
    height = 2048;
    frame_index = 10;

    linesize[1] = width / 2;
    linesize[2] = width / 2;

    for (int i = 0; i < 4; i++) {
        if (i == 1 || i == 2) {
            size_t alloc_size = ((size_t)(height / 2)) * linesize[i];
            data[i] = (uint8_t*)calloc(alloc_size, sizeof(uint8_t));
        } else {
            data[i] = NULL;
        }
    }
}