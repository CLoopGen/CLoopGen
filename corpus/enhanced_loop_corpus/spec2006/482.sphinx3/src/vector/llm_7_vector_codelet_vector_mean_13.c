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
    if (n_dim > 0) {
        mean[0] *= (float32)f;
        for (i = 1; i < n_dim; i++) {
            mean[i] *= mean[i-1];
        }
    }
}
