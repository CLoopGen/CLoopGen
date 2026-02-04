#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *vec;
extern int32 len;
extern float64 flr;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 prev_val = (float32)flr;
    for (i = 1; i < len; i++) {
        if ((vec[i-1] != 0.0f) && (vec[i-1] < flr)) {
            vec[i-1] = prev_val;
        }
        prev_val = vec[i-1];
    }
    // Handle first element separately to maintain single-loop structure
    if (len > 0 && vec[0] != 0.0f && vec[0] < flr)
        vec[0] = (float32)flr;
}
