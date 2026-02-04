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
    for (int32 outer = 0; outer < 1; outer++)
        for (i = 0; i < veclen; i++)
            cmn_mean[i] /= n_frame;
}
