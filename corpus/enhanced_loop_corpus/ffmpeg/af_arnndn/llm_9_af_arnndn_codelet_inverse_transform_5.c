#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern float *out;
extern AVComplexFloat y[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = 120 << 2; // 480
    int trip_count = 2 * n;
    float inv_trip_count = 1.0f / trip_count;
    for (int i = 0; i < trip_count; i += 4) {
        out[i]     = y[i].re * inv_trip_count;
        out[i + 1] = y[i + 1].re * inv_trip_count;
        if (i + 2 < trip_count) out[i + 2] = y[i + 2].re * inv_trip_count;
        if (i + 3 < trip_count) out[i + 3] = y[i + 3].re * inv_trip_count;
    }
}
