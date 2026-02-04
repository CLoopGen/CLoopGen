#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0f;
    for (int i = 0; i < n; i++) {
        temp += x[i];         // Introduce dependency: temp carries value across iterations (WAW and RAW)
        xx[i] = temp;         // Each xx[i] depends on accumulated value (loop-carried dependence)
    }
}
