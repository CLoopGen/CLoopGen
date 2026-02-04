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
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = veclen - 1; i >= 0; i--)
        cmn_mean[i] /= n_frame;
}
