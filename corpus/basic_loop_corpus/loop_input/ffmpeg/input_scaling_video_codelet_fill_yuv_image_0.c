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
    frame_index = 5;
    width = 1024;
    height = 512;
    linesize[0] = width;

    data[0] = (uint8_t*)calloc(height, linesize[0]);
    data[1] = (uint8_t*)calloc(height, linesize[1]);
    data[2] = (uint8_t*)calloc(height, linesize[2]);
    data[3] = (uint8_t*)calloc(height, linesize[3]);
}