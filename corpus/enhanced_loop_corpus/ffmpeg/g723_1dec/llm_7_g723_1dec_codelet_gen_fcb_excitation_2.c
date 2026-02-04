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
    for (i = lag; i < 60; i += 2) {
        if (i + 1 < 60) {
            vector[i] += beta * vector[i - lag] >> 15;
            vector[i + 1] += beta * vector[i + 1 - lag] >> 15;
        } else {
            vector[i] += beta * vector[i - lag] >> 15;
        }
    }
}
