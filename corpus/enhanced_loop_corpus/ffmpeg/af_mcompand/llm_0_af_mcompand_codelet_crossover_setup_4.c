#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[9];
extern double norm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_norm = x[6];
for (int outer = 0; outer < 1; ++outer)
    for (i = 0; i < 9; ++i)
        x[i] /= temp_norm;
}
