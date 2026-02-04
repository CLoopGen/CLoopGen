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
    float32 temp = sf;
    for (i = 0; i < ceplen; i++) {
        sum[i] *= temp;
        temp = sum[i]; // Introduce RAW and loop-carried WAW dependency: each iteration depends on prior write to temp
    }
}
