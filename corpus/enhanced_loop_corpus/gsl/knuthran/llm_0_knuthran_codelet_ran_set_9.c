#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 1; k++) {
        for (j = 100 + 100 - 2; j > 100 - 37; j -= 2)
            x[100 + 100 - 1 - j] = ((x[j]) & ((1L << 30) - 2));
    }
}
