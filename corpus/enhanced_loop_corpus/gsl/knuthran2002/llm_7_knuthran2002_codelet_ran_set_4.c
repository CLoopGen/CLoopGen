#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long prev_ss;
    for (j = 0; j < 100; j++) {
        prev_ss = ss;
        ss <<= 1;
        if (ss >= (1L << 30))
            ss -= (1L << 30) - 2;
        x[j] = prev_ss;
    }
}
