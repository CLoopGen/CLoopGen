#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **filterPos;
int xInc;
int dstW;
int filterSize;
int64_t *filter;
int64_t fone;
int i;
int64_t xDstInSrc;

void init_vars() {
    dstW = 10000;
    filterSize = 8;
    xInc = 17500;
    fone = (1LL << 32);
    xDstInSrc = (1LL << 31);

    filterPos = (int32_t**)calloc(1, sizeof(int32_t*));
    if (!filterPos) exit(1);
    filterPos[0] = (int32_t*)calloc(dstW, sizeof(int32_t));
    if (!filterPos[0]) exit(1);

    filter = (int64_t*)calloc(dstW * filterSize, sizeof(int64_t));
    if (!filter) exit(1);
}