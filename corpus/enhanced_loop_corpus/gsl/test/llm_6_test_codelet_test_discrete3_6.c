#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double P[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 1.0 / 20;
    for (i = 0; i < 20; ++i)
        P[i] = temp;
}
