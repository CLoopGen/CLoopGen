#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_var;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int32 i = 0; i < veclen; i += 4) {
    cmn_var[i] = 0.;
    if (i + 1 < veclen) cmn_var[i + 1] = 0.;
    if (i + 2 < veclen) cmn_var[i + 2] = 0.;
    if (i + 3 < veclen) cmn_var[i + 3] = 0.;
}
}
