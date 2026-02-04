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
    int32 j;
    for (i = 0; i < ceplen * 2; i += 2) {
        j = i < ceplen ? i : ceplen - 1;
        cur_mean[j] = (sum[j] + sum[j]) * sf * 0.5f;
    }
}
