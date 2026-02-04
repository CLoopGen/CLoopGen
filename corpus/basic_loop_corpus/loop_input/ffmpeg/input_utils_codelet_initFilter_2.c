#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dstW = 1024;
int flags = 524288;
int i;
int filterSize = 256;
int filter2Size = 128;
int minFilterSize = 64;
int64_t *filter;
int64_t *filter2;

void init_vars() {
    filter = (int64_t*)calloc(dstW * filterSize, sizeof(int64_t));
    filter2 = (int64_t*)calloc(dstW * filter2Size, sizeof(int64_t));

    for (int idx = 0; idx < dstW * filter2Size; idx++) {
        filter2[idx] = (int64_t)(idx & 0xFF);
    }
}