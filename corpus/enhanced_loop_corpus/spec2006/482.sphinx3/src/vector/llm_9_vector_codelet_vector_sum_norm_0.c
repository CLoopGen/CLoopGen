#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *vec;
extern int32 len;
extern float64 sum;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float64 local_sum1 = 0.0, local_sum2 = 0.0;
    int32 step = 2;
    for (i = 0; i < len; i++) {
        local_sum1 += vec[i] * vec[i];        // Squared accumulation
        local_sum2 += 1.0 / (vec[i] + 1e-9); // Inverse with small offset to avoid division by zero
    }
    sum = local_sum1 + local_sum2;
}
