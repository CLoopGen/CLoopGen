#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern  float threshold;
extern  float frac;
extern  float shift;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *ptr = block;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            const float temp = (ptr[j] >= 0 ? ptr[j] : -ptr[j]);
            if (temp <= threshold)
                ptr[j] *= frac;
            else
                ptr[j] = (ptr[j] < 0.F ? -1.F : (ptr[j] > 0.F ? 1.F : 0.F)) * (temp - shift);
        }
        ptr += stride;
    }
}
