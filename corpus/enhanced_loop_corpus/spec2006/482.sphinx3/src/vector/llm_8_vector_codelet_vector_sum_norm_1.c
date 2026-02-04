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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            vec[i]     = (float32)(((float64)vec[i]) * (float64)f);
            vec[i + 1] = (float32)(((float64)vec[i + 1]) * (float64)f);
        } else {
            vec[i] = (float32)(((float64)vec[i]) * (float64)f);
        }
    }
}
