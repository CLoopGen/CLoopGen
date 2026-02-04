#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **filterPos;
int xInc;
int dstW = 1 << 20;
int filterSize = 5;
int64_t *filter;
int64_t fone = (int64_t)1 << 32;
int i;
int64_t xDstInSrc;

void init_vars() {
    filterPos = malloc(sizeof(int32_t*));
    if (!filterPos) exit(1);
    *filterPos = malloc(dstW * sizeof(int32_t));
    if (!(*filterPos)) exit(1);

    filter = malloc(dstW * sizeof(int64_t));
    if (!filter) exit(1);

    xInc = 12345;
    xDstInSrc = ((int64_t)1) << 16;
    fone = (int64_t)1 << 32;
}