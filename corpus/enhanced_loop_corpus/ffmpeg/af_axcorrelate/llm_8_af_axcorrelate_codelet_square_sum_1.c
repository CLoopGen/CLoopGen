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
    for (int i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            square_sum += x[i] * y[i] + x[i+1] * y[i+1];
        } else {
            square_sum += x[i] * y[i];
        }
    }
}
