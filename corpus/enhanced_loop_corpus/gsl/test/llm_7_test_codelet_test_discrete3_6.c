#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double P[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    P[0] = 1.0 / 20;
    for (i = 1; i < 20; ++i)
        P[i] = P[i-1]; // Introduce RAW and loop-carried dependency: each iteration depends on previous write
}
