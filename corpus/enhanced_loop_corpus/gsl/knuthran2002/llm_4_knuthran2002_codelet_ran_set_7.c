#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 100 - 1; j > 0; j--) {
        if (j % 2 == 0) {
            x[j + j] = x[j];
        }
        if (j % 3 != 0) {
            x[j + j - 1] = 0;
        }
    }
}
