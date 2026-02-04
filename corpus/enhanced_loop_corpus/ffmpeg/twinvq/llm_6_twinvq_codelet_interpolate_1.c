#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern float v2;
extern int size;
extern int i;
extern float step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = v2;
    for (i = 0; i < size; i++) {
        temp += step;
        out[i] = temp;
    }
    v2 = temp;
}
