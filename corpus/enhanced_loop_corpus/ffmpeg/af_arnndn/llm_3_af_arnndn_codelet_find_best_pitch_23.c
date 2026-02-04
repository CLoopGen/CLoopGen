#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int len;
extern float Syy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to start
    for (int j = len - 1; j >= 0; j--)
        Syy += y[j] * y[j];
}
