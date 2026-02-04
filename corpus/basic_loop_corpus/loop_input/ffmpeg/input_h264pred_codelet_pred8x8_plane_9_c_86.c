#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 1024;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H = 0;
int V = 0;

static uint16_t data[262144]; // 512KB of data (262144 elements * 2 bytes)

void init_vars() {
    size_t i;
    stride = 1024;
    for (i = 0; i < 262144; ++i) {
        data[i] = (uint16_t)(i & 0xFFFF);
    }
    src0 = data + 4; // Ensure at least 4 elements before and after
    src1 = data + 8192;
    src2 = data + 16384;
    H = 0;
    V = 0;
}