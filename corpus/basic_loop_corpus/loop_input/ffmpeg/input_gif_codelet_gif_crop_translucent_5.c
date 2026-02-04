#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int trans;
int w;
int y_end;
int is_trans;

void init_vars() {
    w = 16777216; // ~16.7M elements to target ~0.01 sec runtime
    linesize = w;
    y_end = 0;
    trans = 42;
    is_trans = 1;

    buf = (uint8_t*)calloc(w, sizeof(uint8_t));
    if (!buf) {
        exit(1);
    }

    for (int i = 0; i < w; i++) {
        buf[i] = (i < w / 2) ? trans : trans + 1;
    }
}