#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp = ss;
    for (j = 0; j < 100; j++) {
        x[j] = temp;
        temp <<= 1;
        if (temp >= (1L << 30))
            temp -= (1L << 30) - 2;
    }
    ss = temp; // Move write to ss outside the loop (eliminates loop-carried WAW dependency on ss)
}
