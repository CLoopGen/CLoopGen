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
    if (size > 0) {
        square_sum += x[0] * y[0];
        for (int i = 1; i < size; i++) {
            float prod = x[i] * y[i];
            float prev_prod = x[i-1] * y[i-1];
            square_sum += prod + prev_prod;
        }
        square_sum *= 0.5f;
    }
}
