#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint32_t ff_cga_palette[16] = {
    0x000000, 0x0000AA, 0x00AA00, 0x00AAAA, 0xAA0000, 0xAA00AA, 0xAA5500,
    0xAAAAAA, 0x555555, 0x5555FF, 0x55FF55, 0x55FFFF, 0xFF5555, 0xFF55FF,
    0xFFFF55, 0xFFFFFF
};

uint8_t cga_mode45_index[6][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15},
    {0, 2, 4, 6},
    {1, 3, 5, 7}
};

uint32_t *palette = NULL;
int npal = 4;
int i = 0;

void init_vars() {
    npal = 4;
    palette = (uint32_t *)malloc(npal * sizeof(uint32_t));
    if (!palette) {
        exit(1);
    }
}