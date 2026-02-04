#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int x;
int y;
uint8_t *cmkp;
uint8_t *cmkpU;
uint8_t *cmkpV;
int width;
int height;
int cmk_linesize;
int cmk_linesizeUV;
uint8_t *cmkpp;
uint8_t *cmkpn;
uint8_t *cmkpnn;

void init_vars() {
    width = 1024;
    height = 512;
    cmk_linesize = width;
    cmk_linesizeUV = width / 2;

    size_t lum_size = (size_t)height * cmk_linesize;
    size_t chr_size = (size_t)height * cmk_linesizeUV;

    cmkp = (uint8_t*)calloc(lum_size, sizeof(uint8_t));
    cmkpp = (uint8_t*)calloc(lum_size, sizeof(uint8_t));
    cmkpn = (uint8_t*)calloc(lum_size, sizeof(uint8_t));
    cmkpnn = (uint8_t*)calloc(lum_size, sizeof(uint8_t));
    cmkpU = (uint8_t*)calloc(chr_size, sizeof(uint8_t));
    cmkpV = (uint8_t*)calloc(chr_size, sizeof(uint8_t));

    for (size_t i = 0; i < chr_size; i++) {
        cmkpU[i] = rand() % 256;
        cmkpV[i] = rand() % 256;
    }

    for (size_t i = 0; i < lum_size; i++) {
        cmkp[i] = rand() % 256;
        cmkpp[i] = rand() % 256;
        cmkpn[i] = rand() % 256;
        cmkpnn[i] = rand() % 256;
    }

    x = 0;
    y = 0;
}