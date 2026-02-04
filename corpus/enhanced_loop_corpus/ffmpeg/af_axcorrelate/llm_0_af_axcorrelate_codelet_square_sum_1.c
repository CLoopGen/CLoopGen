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
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 1; j++) {
            square_sum += x[i] * y[i];
        }
    }
}
