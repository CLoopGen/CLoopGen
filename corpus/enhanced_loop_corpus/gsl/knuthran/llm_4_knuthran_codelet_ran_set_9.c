#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 198; j > 63; j -= 2) {
        if (j % 4 != 0)
            x[199 - j] = (x[j]) & ((1L << 30) - 2);
    }
}
