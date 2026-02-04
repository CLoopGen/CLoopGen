#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short JCOEF;
typedef unsigned short UJCOEF;

JCOEF *block;
int *jpeg_natural_order_start;
int Al;
UJCOEF *values;
int k;
int temp;
int temp2;
size_t zerobits;
int Sl0;

void init_vars() {
    Sl0 = 64;
    Al = 1;

    block = (JCOEF*)calloc(64, sizeof(JCOEF));
    jpeg_natural_order_start = (int*)malloc(64 * sizeof(int));
    values = (UJCOEF*)calloc(128, sizeof(UJCOEF));

    for (int i = 0; i < 64; i++) {
        jpeg_natural_order_start[i] = i;
    }

    for (int i = 0; i < 64; i++) {
        block[i] = (JCOEF)(i * 4 - 32);
    }

    zerobits = 0;
}