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
    float64 temp_dist = dist;
    for (i = 0; i < len; i++) {
        float64 diff_local = (vec[i] - mean[i]);
        temp_dist -= diff_local * diff_local * varinv[i];
    }
    dist = temp_dist;
}
