#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *initvalu;
extern float *initvalu_temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 45; i++) {
        float a = initvalu[i] * 2.0f;
        float b = initvalu[90 - i] * 0.5f;
        initvalu_temp[i] = a + b;
        initvalu_temp[90 - i] = a - b;
    }
}
