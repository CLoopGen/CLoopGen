#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct {
    uint8_t count;
    uint8_t outch[8];
    int32_t forco[8][10];
    int32_t coeff[8][10];
    uint8_t fbits[8];
    int8_t shift[8];
} MatrixParams;

MatrixParams *dst;
MatrixParams *src;
unsigned int channel;
unsigned int count;

static MatrixParams src_data;
static MatrixParams dst_data;

void init_vars() {
    // Initialize the global pointers
    src = &src_data;
    dst = &dst_data;

    // Initialize src data to non-zero values to simulate realistic input
    src->count = 8;
    for (int i = 0; i < 8; i++) {
        src->outch[i] = (uint8_t)(i + 1);
        src->fbits[i] = (uint8_t)(8 - i);
        src->shift[i] = (int8_t)(4 - i);
        for (int j = 0; j < 8; j++) {
            src->coeff[j][i] = (int32_t)(i * 8 + j + 1);
        }
        for (int j = 0; j < 10; j++) {
            src->forco[i][j] = (int32_t)(i * 10 + j + 1);
        }
    }

    // Zero-initialize dst to ensure we're testing copy behavior
    memset(dst, 0, sizeof(MatrixParams));

    // Ensure loop bounds are safe: channel < 8 and count < 8 as per loop logic
    channel = 0;
    count = 0;
}