#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp = x[0];
    for (j = 100; j > 1; j--) {
        x[j] = x[j - 1];
    }
    x[1] = temp;
}
