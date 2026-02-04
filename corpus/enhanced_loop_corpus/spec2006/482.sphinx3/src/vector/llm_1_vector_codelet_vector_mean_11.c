#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 outer = n_dim / 2 + 1;
    int32 inner;
    for (i = 0; i < outer; i++) {
        inner = i * 2;
        if (inner < n_dim) mean[inner] = 0.;
        inner = i * 2 + 1;
        if (inner < n_dim) mean[inner] = 0.;
    }
}
