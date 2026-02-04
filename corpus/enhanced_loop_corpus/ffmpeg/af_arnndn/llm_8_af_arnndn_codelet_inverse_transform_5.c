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
    int trip_count = 2 * (120 << 2);
    float scale = 1.0f / trip_count;
    for (int i = 0; i < trip_count; i++) {
        float real_part = y[i].re;
        out[i] = real_part * scale;
    }
}
