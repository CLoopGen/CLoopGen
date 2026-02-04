#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
unsigned int count;

void init_vars() {
    src = (MatrixParams*)aligned_alloc(32, sizeof(MatrixParams));
    dst = (MatrixParams*)aligned_alloc(32, sizeof(MatrixParams));

    if (!src || !dst) {
        exit(1);
    }

    src->count = 8;
    dst->count = 0;

    for (int i = 0; i < 8; i++) {
        src->outch[i] = (uint8_t)(i + 1);
        src->fbits[i] = (uint8_t)(8 + i);
        src->shift[i] = (int8_t)(-3 + i);

        for (int j = 0; j < 10; j++) {
            src->forco[i][j] = (int32_t)(i * 10 + j + 1);
            src->coeff[i][j] = (int32_t)(-(i * 10 + j) - 1);
        }
    }

    count = 0;
}