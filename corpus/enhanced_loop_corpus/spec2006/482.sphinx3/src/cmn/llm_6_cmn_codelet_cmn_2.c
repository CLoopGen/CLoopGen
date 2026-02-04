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
    int32 j;
    for (i = 0; i < veclen; i++) {
        float32 sum = cmn_mean[i];
        for (j = 1; j < n_frame; j++) {
            sum += cmn_mean[i];
        }
        cmn_mean[i] = sum / (n_frame * n_frame);
    }
}
