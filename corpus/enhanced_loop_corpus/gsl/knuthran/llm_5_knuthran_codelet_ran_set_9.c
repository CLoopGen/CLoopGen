#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 198; j > 63; j -= 2) {
        if (x[j] >= 0)
            x[199 - j] = x[j] & ((1L << 30) - 2);
        else
            x[199 - j] = 0;
    }
}
