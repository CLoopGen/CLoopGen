#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 50; j > 0; j--) {
        x[j * 2] = x[j];
        x[j * 2 - 1] = 0;
    }
}
