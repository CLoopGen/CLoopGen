#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *vec;
extern float32 *mean;
extern float32 *varinv;
extern int32 len;
extern float64 dist;
extern float64 diff;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dist = 0.0;
    for (i = 0; i < len; i++) {
        float64 d1 = vec[i] - mean[i];
        float64 d2 = vec[i] + mean[i];
        float64 term1 = d1 * d1 * varinv[i];
        float64 term2 = d2 * d2 * varinv[i];
        dist += term1 - term2;
    }
}
