#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

extern int32 ceplen;
extern float32 *cur_mean;
extern float32 *sum;
extern float32 sf;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ceplen; i++) {
        if (sf == 0.0f) {
            cur_mean[i] = 0.0f;
            continue;
        }
        cur_mean[i] = sum[i] * sf;
    }
}
