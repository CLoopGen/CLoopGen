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
    int32 j;
    for (i = 0; i < ceplen; i++) {
        j = ceplen - 1 - i;
        sum[j] *= sf;
    }
}
