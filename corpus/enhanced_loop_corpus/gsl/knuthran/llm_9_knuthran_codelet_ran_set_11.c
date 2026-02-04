#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 50; j > 0; j--) {
        x[2*j] = x[2*j - 1];
        x[2*j + 1] = x[2*j];
    }
}
