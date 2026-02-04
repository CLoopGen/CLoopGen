#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern float temp[54];
extern float gain;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_local[54];
    for (i = 0; i < length; i++) {
        temp_local[i] = temp[i] * gain;
    }
    for (i = 0; i < length; i++) {
        temp[i] = temp_local[i];
    }
}
