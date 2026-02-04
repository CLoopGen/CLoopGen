#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern float32 **data;
extern int32 n_vec;
extern int32 n_dim;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < n_dim; j++) {
        float32 sum = 0.0f;
        for (i = 0; i < n_vec; i++)
            sum += data[i][j];
        mean[j] = sum;
    }
}
