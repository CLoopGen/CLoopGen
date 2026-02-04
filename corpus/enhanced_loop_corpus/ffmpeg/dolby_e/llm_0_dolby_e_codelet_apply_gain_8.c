#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern float a;
extern float b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 1792; i++) {
    for (j = 0; j < 1; j++) {
        output[i] *= a * (1792 - i - 1) + b * i;
    }
}
}
