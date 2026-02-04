#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int linesize;
int w = 1024;
int h = 1024;
int x;
int y;
int current_pass = 100;
int has_anything_changed;

uint8_t *current_pixel0;
uint8_t *current_pixel;

static uint8_t *data_buffer;

void init_vars() {
    linesize = w;
    data_buffer = (uint8_t*)calloc(h, linesize);
    if (!data_buffer) {
        exit(1);
    }
    current_pixel0 = data_buffer + linesize + 1;
    has_anything_changed = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            data_buffer[i * linesize + j] = 99 + (i % 3); 
        }
    }
}