#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 n_frame;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 accumulator = 1.0f;
    for (i = 0; i < veclen; i++) {
        accumulator *= cmn_mean[i];
        cmn_mean[i] = accumulator / n_frame;
    }
}
