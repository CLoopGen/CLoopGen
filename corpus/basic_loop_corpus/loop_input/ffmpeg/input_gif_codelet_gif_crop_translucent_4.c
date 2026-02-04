#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int *y_start;
int trans;
int w;
int is_trans;

void init_vars() {
    w = 16777216; // 16M elements, roughly tuned for ~0.01 sec on modern CPU
    linesize = w;
    trans = 42;
    is_trans = 1;

    buf = aligned_alloc(32, (size_t)linesize * sizeof(uint8_t));
    if (!buf) exit(1);

    y_start = malloc(sizeof(int));
    if (!y_start) exit(1);
    *y_start = 0;

    for (int i = 0; i < w; i++) {
        buf[linesize * (*y_start) + i] = trans;
    }

    // Ensure at least one mismatch to trigger is_trans = 0 if needed
    if (w > 0) {
        buf[linesize * (*y_start) + w/2] = trans + 1;
    }
}