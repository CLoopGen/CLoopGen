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
    // Variant 2: Reverse consecutive memory access
    for (i = len - 1; i >= 0; i--) {
        diff = (vec[i] - mean[i]);
        dist -= diff * diff * varinv[i];
    }
}
