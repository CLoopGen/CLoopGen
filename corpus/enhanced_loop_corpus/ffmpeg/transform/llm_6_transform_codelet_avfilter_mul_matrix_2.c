#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern float scalar;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[9];
    for (i = 0; i < 9; i++) {
        temp[i] = m1[i] * scalar;
    }
    for (i = 0; i < 9; i++) {
        result[i] = temp[i];
    }
}
