#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (int i = 0; i < N; i++) {
        temp = output[i];
        output[i] = (0 > temp) ? 0 : temp;
    }
}
