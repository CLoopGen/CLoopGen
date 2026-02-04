#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *vec;
extern int32 len;
extern float64 f;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        float32 prev = vec[0];
        vec[0] = (float32)((float64)prev * (float64)f);
        for (i = 1; i < len; i++) {
            float32 curr = vec[i];
            vec[i] = (float32)((float64)curr * (float64)f + (float64)prev);
            prev = curr;
        }
    }
}
