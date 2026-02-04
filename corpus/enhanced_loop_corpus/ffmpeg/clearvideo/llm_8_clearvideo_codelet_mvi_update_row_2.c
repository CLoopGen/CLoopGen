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
    int limit = mvi->mb_stride * 2;
    for (i = 0; i < limit; i += 2) {
        mvi->mv[i / 2] = mvi->mv[mvi->mb_stride + (i / 2)];
    }
}
