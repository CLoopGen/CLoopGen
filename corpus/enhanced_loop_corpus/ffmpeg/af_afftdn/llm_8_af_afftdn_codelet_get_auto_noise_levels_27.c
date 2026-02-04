#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *levels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 0;
int step = 1;
for (int i = start; i < 15 * step; i += step) {
    levels[i] = -100.0;
    levels[i] = levels[i] * 1.1 + 2.5;
    levels[i] = levels[i] > -90.0 ? levels[i] : -90.0;
}
}
