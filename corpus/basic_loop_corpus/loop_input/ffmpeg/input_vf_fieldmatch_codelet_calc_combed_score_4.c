#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;
int blockx = 16;
int blocky = 16;
int xhalf = 8;
int yhalf = 8;
int cmk_linesize = 256;
uint8_t *cmkp;
int width = 256;
int height = 256;
int xblocks4 = 64;
int *c_array;
int heighta = 0;

void init_vars() {
    const size_t total_c_array_size = xblocks4 * ((height + blocky - 1) / blocky) * 4;
    c_array = (int*)calloc(total_c_array_size, sizeof(int));
    if (!c_array) exit(1);

    const size_t cmk_size = cmk_linesize * height;
    uint8_t* cmk_base = (uint8_t*)calloc(cmk_size + 2 * cmk_linesize, sizeof(uint8_t));
    if (!cmk_base) exit(1);

    cmkp = cmk_base + cmk_linesize;

    for (int i = 0; i < width * height; ++i) {
        cmkp[i] = 255;
    }
}