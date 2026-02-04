#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
int x;
int y;
int xy;
int yz;
int temp[64];

static uint8_t src_buffer[262144]; // 256 KB buffer to ensure ~0.01 sec runtime

void init_vars() {
    stride = 4096; // Ensures sufficient spacing between rows to prevent overlap
    src = src_buffer;

    for (int i = 0; i < 64; i++) {
        temp[i] = rand() & 0xFF; // Initialize temp with random data in valid range
    }

    x = 0;
    y = 0;
    xy = 0;
    yz = 0;
}