#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 100 - 1; j > 0; j--) {
        if (x[j] != 0)
            x[j + j] = x[j];
        else
            x[j + j] = 0;
    }
}
