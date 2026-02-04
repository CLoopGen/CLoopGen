#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (i = 0; i < veclen; i++) {
        cmn_mean[i] = 0.;
        for (j = 1; j < 4; j++) {
            cmn_mean[i] += (float32)j * 0.1f;
        }
    }
}
