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
    int32 step = 2;
    for (i = 0; i < veclen; i += step) {
        if (i + 1 < veclen) {
            cmn_mean[i] /= n_frame;
            cmn_mean[i + 1] /= n_frame;
        } else {
            cmn_mean[i] /= n_frame;
        }
    }
}
