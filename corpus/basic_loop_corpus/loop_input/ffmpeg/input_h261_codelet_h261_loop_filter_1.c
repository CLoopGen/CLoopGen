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

void init_vars() {
    stride = 64;
    src = (uint8_t*)aligned_alloc(32, stride * 8 * sizeof(uint8_t));
    for (int i = 0; i < stride * 8; i++) {
        src[i] = rand() % 256;
    }
    for (int i = 0; i < 64; i++) {
        temp[i] = 0;
    }
    x = 0;
    y = 0;
    xy = 0;
    yz = 0;
}