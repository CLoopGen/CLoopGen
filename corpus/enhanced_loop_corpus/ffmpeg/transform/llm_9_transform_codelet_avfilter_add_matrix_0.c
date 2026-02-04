#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern  float *m2;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i++) {
        float a = m1[i] * 2.0f;
        float b = m2[i] * 3.0f;
        float c = a - b;
        result[i] = c + (m1[i] * m2[i]);
    }
}
