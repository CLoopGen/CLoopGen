#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *excitation;
extern float gain;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = gain;
    for (i = 0; i < length; i++) {
        excitation[i] *= temp;
    }
}
