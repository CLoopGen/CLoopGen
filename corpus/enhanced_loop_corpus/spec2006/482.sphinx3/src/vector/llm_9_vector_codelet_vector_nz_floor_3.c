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
    float32 floor_val = (float32)flr;
    for (i = 0; i < len; i++) {
        float32 v = vec[i];
        if (v != 0.0f) {
            if (v < floor_val) {
                v = floor_val;
            }
            vec[i] = v;
        }
    }
}
