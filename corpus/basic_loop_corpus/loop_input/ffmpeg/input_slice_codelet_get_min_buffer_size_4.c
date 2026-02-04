#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *out_lum_size;
int *out_chr_size;
int lumY;
int dstH;
int chrDstH;
int *lumFilterPos;
int *chrFilterPos;
int lumFilterSize;
int chrFilterSize;
int chrSubSample;

void init_vars() {
    dstH = 8192;
    chrDstH = 4096;
    lumFilterSize = 8;
    chrFilterSize = 6;
    chrSubSample = 1;

    out_lum_size = (int*)calloc(1, sizeof(int));
    out_chr_size = (int*)calloc(1, sizeof(int));

    lumFilterPos = (int*)malloc(dstH * sizeof(int));
    chrFilterPos = (int*)malloc(chrDstH * sizeof(int));

    for (int i = 0; i < dstH; i++) {
        lumFilterPos[i] = (i * 16) % 1024;
    }

    for (int i = 0; i < chrDstH; i++) {
        chrFilterPos[i] = (i * 8) % 512;
    }
}