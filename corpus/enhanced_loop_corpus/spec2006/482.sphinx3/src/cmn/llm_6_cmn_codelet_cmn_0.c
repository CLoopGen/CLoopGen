#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 temp = 0.0;
    for (i = 0; i < veclen; i++) {
        temp += cmn_mean[i];
        cmn_mean[i] = 0.;
    }
    // Introduces a temporary accumulation (read-after-write dependency within the loop)
    // Creates a loop-carried dependence via 'temp', though unused afterward.
    // RAW dependency: cmn_mean[i] is read before being written in the same iteration.
}
