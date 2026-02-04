#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; j < 200; j += 2) {
        x[j] = 0;
        if (j + 1 < 200) x[j + 1] = 0;
    }
}
