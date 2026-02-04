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
    // Variant 2: Strided memory access, processing every second element forward and backward
    int stride = mvi->mb_stride;
    for (i = 0; i < stride; i += 2) {
        mvi->mv[i] = mvi->mv[stride + i];
        if (i + 1 < stride) {
            mvi->mv[i + 1] = mvi->mv[stride + i + 1];
        }
    }
}
