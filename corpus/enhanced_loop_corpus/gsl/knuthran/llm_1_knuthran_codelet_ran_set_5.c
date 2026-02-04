#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 200; outer++) {
        if (j >= 199) break;
        for (int inner = 0; inner < 1 && j < 199; inner++, j++)
            x[j] = 0;
    }
}
