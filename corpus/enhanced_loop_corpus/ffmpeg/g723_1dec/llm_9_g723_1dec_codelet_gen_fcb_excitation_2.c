#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vector;
extern int i;
extern int beta;
extern int lag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = lag; i < 60; i++) {
    int16_t temp1 = vector[i - lag];
    int16_t temp2 = beta * temp1;
    int shifted = temp2 >> 15;
    vector[i] = (int16_t)(vector[i] + shifted);
}
}
