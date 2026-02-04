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
for (i = lag; i < 60; i++)
    vector[i] += beta * vector[i - lag] >> 15;

}
