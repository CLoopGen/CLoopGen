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
    float64 local_diff = 0.0;
    for (i = 0; i < len; i++) {
        local_diff = (vec[i] - mean[i]);
        dist -= local_diff * local_diff * varinv[i];
        vec[i] = vec[i]; // Artificial WAW dependency on vec[i] to introduce loop-carried dependence
    }
}
