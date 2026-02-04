#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *a;
extern  float *b;
extern int length;
extern float sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0f;
    for (i = 0; i < length; i++) {
        float prod = a[i] * b[i];
        if (prod > 0.0f) {
            sum += prod;
        }
    }
}
