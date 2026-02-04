#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int size;
extern float square_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    square_sum = 0.0f;
    for (int i = 0; i < size; i++) {
        float prod = x[i] * y[i];
        if (prod > 0.0f) {
            square_sum += prod;
        }
    }
}
