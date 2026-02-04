#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_var;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 scale = 1.5f;
    for (i = 0; i < veclen * 2; i++) {
        int32 idx = i / 2;
        cmn_var[idx] = cmn_var[idx] * scale + 0.f;
    }
}
