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
    float prev = temp[0];
    for (i = 1; i < length; i++) {
        float current = temp[i];
        temp[i] = current * gain + prev;
        prev = current;
    }
    if (length > 0) {
        temp[0] *= gain;
    }
}
