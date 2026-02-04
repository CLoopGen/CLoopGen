#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int i;
int out;
int c;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

static uint8_t dst_buffer[DATA_SIZE];

void init_vars() {
    dst = dst_buffer;
    i = 0;
    out = 0;
    c = DATA_SIZE / 2; // ensures i < c * 2 covers exactly DATA_SIZE iterations
}