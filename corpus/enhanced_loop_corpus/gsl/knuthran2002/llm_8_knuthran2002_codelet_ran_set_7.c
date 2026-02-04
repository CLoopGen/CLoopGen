#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 150 - 1; j > 0; j -= 2) {
        x[j + j] = x[j];
        x[j + j - 1] = 0;
        x[j + j - 2] = x[j - 1];
        x[j + j - 3] = 0;
    }
}
