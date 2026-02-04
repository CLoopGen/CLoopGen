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
        if (sum[i] != 0.0f) {
            cur_mean[i] = sum[i] * sf;
        } else {
            cur_mean[i] = 0.0f;
        }
    }
}
