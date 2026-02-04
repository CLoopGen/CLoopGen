#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *out;
int stride;
int width;
int height;
int bpp;
uint8_t cols[4];
uint8_t grps[4];
uint32_t col;
int x;
int y;

void init_vars() {
    width = 1024;
    height = 512;
    bpp = 2;
    stride = width;

    col = 0xABCDEF12U;

    cols[0] = 0x10;
    cols[1] = 0x20;
    cols[2] = 0x30;
    cols[3] = 0x40;

    grps[0] = 0x05;
    grps[1] = 0x0A;
    grps[2] = 0x0F;
    grps[3] = 0x15;

    out = (uint8_t*)malloc(stride * height * sizeof(uint8_t));
    if (!out) {
        exit(1);
    }
}
