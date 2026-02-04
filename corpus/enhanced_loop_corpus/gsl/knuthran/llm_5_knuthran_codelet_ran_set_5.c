#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; j < 199; j++) {
        x[j] = 0;
        if (j == 50) {
            j += 10; // Skip next 10 iterations artificially
        }
    }
}
