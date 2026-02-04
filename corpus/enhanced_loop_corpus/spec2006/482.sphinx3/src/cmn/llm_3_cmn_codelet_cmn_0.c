#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 *indices = (int32*)__builtin_alloca(veclen * sizeof(int32));
    for (int32 j = 0; j < veclen; j++) {
        indices[j] = veclen - 1 - j; // reverse access pattern
    }
    for (i = 0; i < veclen; i++) {
        cmn_mean[indices[i]] = 0.;
    }
}
