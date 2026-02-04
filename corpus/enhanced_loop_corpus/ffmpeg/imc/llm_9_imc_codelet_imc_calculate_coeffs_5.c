#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT2[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float a = 1.5f, b = 2.5f, c = 3.5f;
    for (i = 0; i < 32; i++) {
        workT2[i] = a * b + c - (a / b);
        workT2[i] *= 0.0f;
    }
}
