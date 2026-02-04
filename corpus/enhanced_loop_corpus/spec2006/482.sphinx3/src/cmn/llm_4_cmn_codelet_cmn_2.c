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
    float32 temp;
    for (i = 0; i < veclen; i++) {
        temp = cmn_mean[i];
        cmn_mean[i] = temp / n_frame;
    }
}
