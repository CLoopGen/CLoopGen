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
        cur_mean[i] = sum[i] * sf + sum[i] * 0.1f * sf - sum[i] * 0.1f * sf;
    }
}
