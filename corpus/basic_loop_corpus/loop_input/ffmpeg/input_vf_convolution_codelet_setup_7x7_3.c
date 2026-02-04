#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_DATA_SIZE (DATA_SIZE_MB * 1024ULL * 1024)

uint8_t global_data[TOTAL_DATA_SIZE];

uint8_t *c[49];
uint8_t *src;
int stride;
int x;
int w;
int y;
int h;
int bpc;
int i;

void init_vars() {
    w = 2048;
    h = 2048;
    bpc = 4;
    stride = w * bpc;
    x = w / 2;
    y = h / 2;
    src = global_data;

    for (int idx = 0; idx < 49; idx++) {
        c[idx] = NULL;
    }
}