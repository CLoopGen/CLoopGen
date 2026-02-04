#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t stride;
uint8_t *block;
int x;
int y;
int dist;
int bias;
int dist4;
int dist2;
int bits;
int mask;

#define BLOCK_SIZE (1024 * 1024)
static uint8_t block_data[BLOCK_SIZE];
static uint8_t dst_data[BLOCK_SIZE];

void init_vars() {
    dst = dst_data;
    stride = 64;
    block = block_data;
    x = 0;
    y = 0;
    dist = 32;
    bias = 16;
    dist4 = dist * 4;
    dist2 = dist * 2;
    bits = 0;
    mask = 0;

    for (int i = 0; i < BLOCK_SIZE; i++) {
        block_data[i] = (uint8_t)(i % 256);
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        dst_data[i] = 0;
    }
}