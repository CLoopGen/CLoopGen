#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

extern int32 ceplen;
extern float32 *sum;
extern float32 sf;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 step = 2;
    for (i = 0; i < ceplen; i += step) {
        sum[i] *= sf;
        if (i + 1 < ceplen) {
            sum[i + 1] *= sf;
        }
    }
}
