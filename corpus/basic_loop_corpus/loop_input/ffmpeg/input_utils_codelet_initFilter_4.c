#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **filterPos;
int dstW;
int filterSize;
int64_t *filter;
int64_t fone;
int i;

void init_vars() {
    dstW = 1000000; // ~1M elements to target ~0.01 sec runtime
    filterSize = 4;
    fone = 1LL;

    filter = (int64_t*)calloc(dstW * filterSize, sizeof(int64_t));
    if (!filter) exit(1);

    filterPos = (int32_t**)malloc(sizeof(int32_t*));
    if (!filterPos) exit(1);
    *filterPos = (int32_t*)malloc(dstW * sizeof(int32_t));
    if (!(*filterPos)) exit(1);
}