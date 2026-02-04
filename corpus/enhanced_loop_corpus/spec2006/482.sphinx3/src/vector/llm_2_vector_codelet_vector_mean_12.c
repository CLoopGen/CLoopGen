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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing data[i][j] in row-major order, we stride through the data by fixing j and varying i with a step pattern.
    // Here we maintain the same logical operation but conceptually change access to be more column-wise across vectors.
    for (j = 0; j < n_dim; j++) {
        float32 temp_sum = 0.0f;
        for (i = 0; i < n_vec; i++) {
            temp_sum += data[i][j];  // Strided access: jumping across rows for fixed dimension j
        }
        mean[j] += temp_sum;
    }
}
