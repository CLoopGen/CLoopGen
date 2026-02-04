#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
ptrdiff_t stride;
uint8_t *minp;
uint8_t *maxp;
int v_r;
int v_g;
int v_b;
int mind;
int maxd;
int x;
int y;

#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 65536
#define DATA_SIZE (BLOCK_HEIGHT * BLOCK_WIDTH)

static uint8_t data[DATA_SIZE];

void init_vars() {
    block = data;
    stride = BLOCK_WIDTH;
    minp = block;
    maxp = block;
    v_r = 10;
    v_g = 59;
    v_b = 21;
    mind = 1000000;
    maxd = -1000000;
    x = 0;
    y = 0;

    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = rand() % 256;
    }
}