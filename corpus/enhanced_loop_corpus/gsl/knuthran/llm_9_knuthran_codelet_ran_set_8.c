#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 50; j > 0; j--) {
        x[j * 4] = x[j * 2];
        x[j * 4 + 1] = x[j * 2 + 1];
        x[j * 4 + 2] = x[j * 2 + 2];
        x[j * 4 + 3] = x[j * 2 + 3];
    }
}
