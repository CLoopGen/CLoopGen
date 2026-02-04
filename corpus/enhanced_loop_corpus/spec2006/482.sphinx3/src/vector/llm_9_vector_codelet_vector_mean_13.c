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
    float32 f32_val = (float32)f;
    float32 sum = 1.0f;
    for (i = 0; i < n_dim; i++) {
        mean[i] *= f32_val;
        sum += mean[i] + f32_val * 0.5f;
        mean[i] += sum * 0.01f;
    }
}
