#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 198; j >= 100; j--) {
        if (j % 2 == 0) {
            x[j - 63] = ((x[j - 63] - x[j]) & ((1L << 30) - 1));
        } else {
            x[j - 100] = ((x[j - 100] - x[j]) & ((1L << 30) - 1));
        }
    }
}
