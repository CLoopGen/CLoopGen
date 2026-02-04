#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double P[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (i = 0; i < 20; i += 2)
        P[i] = 1. / 20;
    for (i = 1; i < 20; i += 2)
        P[i] = 1. / 20;
}
