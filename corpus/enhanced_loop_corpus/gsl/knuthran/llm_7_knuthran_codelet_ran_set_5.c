#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp = 0;
    for (; j < 100 + 100 - 1; j++) {
        temp += j;
        x[j] = temp;
    }
    x[198] = temp; // Ensure last value is captured if needed
}
