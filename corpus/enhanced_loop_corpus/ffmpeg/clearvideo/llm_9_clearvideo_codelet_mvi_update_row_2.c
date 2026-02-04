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
    int stride = mvi->mb_stride;
    int offset = stride;
    for (i = 0; i < stride; i++) {
        mvi->mv[i] = mvi->mv[offset + i];
        mvi->mv[stride + i] = mvi->mv[offset + i]; // Duplicate assignment to increase computation
    }
}
