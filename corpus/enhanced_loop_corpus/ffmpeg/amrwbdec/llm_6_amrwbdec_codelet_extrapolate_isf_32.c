#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.80000000000000004;
    for (i = 1; i < 20; i++) {
        isf[i] *= temp;
        isf[i] += isf[i-1] * 0.1; // Introduce RAW dependency: each iteration reads previous write
    }
}
