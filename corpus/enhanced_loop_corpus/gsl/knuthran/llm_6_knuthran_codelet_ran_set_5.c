#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; j < 100 + 100 - 1; j++) {
        x[j] = x[j] + 1;
        x[j] = x[j] - 1;
    }
}
