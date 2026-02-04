#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 1024;
uint8_t *src0;
uint8_t *src1;
uint8_t *src2;
int H = 0;
int V = 0;

static uint8_t data[4 * 1024 * 1024];

void init_vars() {
    src0 = &data[2 * 1024 * 1024];
    src1 = &data[1024 * 1024];
    src2 = &data[3 * 1024 * 1024];
    for (size_t i = 0; i < sizeof(data); ++i) {
        data[i] = rand() % 256;
    }
}