#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < veclen; i++) {
        if (cmn_mean[i] != 0.) {
            cmn_mean[i] = 0.;
        }
    }
}
