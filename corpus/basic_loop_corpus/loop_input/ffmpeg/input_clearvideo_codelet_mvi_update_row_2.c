#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MV {
    int16_t x;
    int16_t y;
} MV;

typedef struct MVInfo {
    int mb_w;
    int mb_h;
    int mb_size;
    int mb_stride;
    int top;
    MV *mv;
} MVInfo;

MV *mv_array;
MVInfo *mvi;
int i;

void init_vars() {
    mvi = (MVInfo *)malloc(sizeof(MVInfo));
    if (!mvi) exit(1);

    mvi->mb_w = 128;
    mvi->mb_h = 128;
    mvi->mb_size = 16;
    mvi->mb_stride = 256;
    mvi->top = 0;

    size_t total_elements = 2 * mvi->mb_stride; // since we access mvi->mb_stride + i
    mv_array = (MV *)calloc(total_elements, sizeof(MV));
    if (!mv_array) exit(1);

    for (size_t idx = 0; idx < total_elements; idx++) {
        mv_array[idx].x = (int16_t)(idx % 32);
        mv_array[idx].y = (int16_t)((idx * 3) % 32);
    }

    mvi->mv = mv_array;
}