#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int src_step;
int radius;
int x;
int sum;

static uint8_t src_data[134217728]; // 128 MB buffer

void init_vars() {
    src_step = 1;
    radius = 134217728; // Ensures loop runs for ~0.01s on modern CPU
    x = 0;
    sum = 0;
    src = src_data;

    for (size_t i = 0; i < sizeof(src_data); i++) {
        src_data[i] = (uint8_t)(i & 0xFF);
    }
}