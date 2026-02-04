#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 190; j > 0; j -= 2) {
        x[j] = x[j - 1] + x[j - 2];
    }
}
