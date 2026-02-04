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

extern MVInfo *mvi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < mvi->mb_stride; i += 2) {
        if (i + 1 < mvi->mb_stride) {
            mvi->mv[i] = mvi->mv[mvi->mb_stride + i];
            mvi->mv[i + 1] = mvi->mv[mvi->mb_stride + i + 1];
        } else {
            mvi->mv[i] = mvi->mv[mvi->mb_stride + i];
        }
    }
}
