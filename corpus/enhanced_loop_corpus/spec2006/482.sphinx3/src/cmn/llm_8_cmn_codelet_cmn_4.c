#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_var;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < veclen; i += 2) {
        if (i + 1 < veclen) {
            cmn_var[i] = 0.;
            cmn_var[i+1] = 0.;
        } else {
            cmn_var[i] = 0.;
        }
    }
}
