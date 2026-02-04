#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;
extern float64 f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 temp;
    for (i = 0; i < n_dim; i++) {
        temp = mean[i] * (float32)f;
        mean[i] = temp;
    }
}
