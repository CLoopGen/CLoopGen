#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **outFilter;
int *outFilterSize;
int dstW;
int i;

void init_vars() {
    dstW = 1024;
    outFilterSize = (int*)malloc(sizeof(int));
    *outFilterSize = 256;

    size_t total_size = (dstW + 3) * (*outFilterSize);
    int16_t *filter_data = (int16_t*)calloc(total_size, sizeof(int16_t));

    outFilter = (int16_t**)malloc(sizeof(int16_t*));
    outFilter[0] = filter_data;
}