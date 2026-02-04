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

static uint16_t data[262144]; // 512 KB of data (262144 elements)

void init_vars() {
    const size_t data_size = sizeof(data) / sizeof(data[0]);
    stride = 1024;
    if (stride <= 0) stride = 1;

    src0 = &data[4]; // Offset to allow access from index -4 to data_size-5
    src1 = &data[stride + 4];
    src2 = &data[data_size - stride - 4];

    for (size_t i = 0; i < data_size; ++i) {
        data[i] = (uint16_t)(i % 313);
    }

    H = 0;
    V = 0;
}