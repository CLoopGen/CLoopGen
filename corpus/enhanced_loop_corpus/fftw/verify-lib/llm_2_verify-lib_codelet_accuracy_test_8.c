#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in two passes)
    for (i = 0; i < 6; i += 2)
        t[i] = 0.;
    for (i = 1; i < 6; i += 2)
        t[i] = 0.;
}
