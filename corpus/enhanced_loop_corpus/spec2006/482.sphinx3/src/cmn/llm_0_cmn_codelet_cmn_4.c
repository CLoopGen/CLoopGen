#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_var;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int32 i = 0; i < veclen; i++)
    for (int32 j = 0; j < 1; j++)
        cmn_var[i] = 0.;
}
