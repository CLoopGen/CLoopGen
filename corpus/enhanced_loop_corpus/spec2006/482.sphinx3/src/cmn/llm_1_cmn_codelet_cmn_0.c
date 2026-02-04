#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (veclen > 0) {
    for (int32 i = 0; i < veclen; i += 2) {
        cmn_mean[i] = 0.;
        if (i + 1 < veclen) {
            cmn_mean[i + 1] = 0.;
        }
    }
}
}
