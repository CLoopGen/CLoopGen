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
    for (i = 0; i < mvi->mb_stride; i++) {
        if (i % 2 == 0) {
            mvi->mv[i] = mvi->mv[mvi->mb_stride + i];
        } else {
            mvi->mv[i].x = 0;
            mvi->mv[i].y = 0;
        }
    }
}
