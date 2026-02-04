#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int y;
int blockx;
int blocky;
int xhalf;
int yhalf;
int cmk_linesize;
uint8_t *cmkp;
int width;
int xblocks4;
int *c_array;

void init_vars() {
    blockx = 16;
    blocky = 16;
    width = 1024;
    xhalf = width / 2;
    yhalf = 512;
    cmk_linesize = width;
    xblocks4 = (width + blockx - 1) / blockx * 4;
    int total_c_array_size = ((yhalf + blocky - 1) / blocky) * xblocks4 + 4;
    c_array = (int*)calloc(total_c_array_size, sizeof(int));
    if (!c_array) exit(1);

    uint8_t* cmk_base = (uint8_t*)calloc((yhalf + 1) * cmk_linesize, sizeof(uint8_t));
    if (!cmk_base) exit(1);
    cmkp = cmk_base + cmk_linesize;

    for (int i = 0; i < yhalf; i++) {
        for (int j = 0; j < width; j++) {
            int val = (rand() % 3 == 0) ? 255 : 0;
            cmk_base[i * cmk_linesize + j] = val;
            if (i == 0) cmk_base[(i + yhalf) * cmk_linesize + j] = val;
        }
    }

    for (int j = 1; j < width - 1; j++) {
        if (cmk_base[cmk_linesize + j - 1] == 255 &&
            cmk_base[cmk_linesize + j] == 255 &&
            cmk_base[cmk_linesize + j + 1] == 255) {
            cmk_base[cmk_linesize + j] = 255;
        }
    }
}