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
int start = lag + 5;
for (i = start; i < 50; i += 2)
    vector[i] += beta * vector[i - lag] >> 15;
}
