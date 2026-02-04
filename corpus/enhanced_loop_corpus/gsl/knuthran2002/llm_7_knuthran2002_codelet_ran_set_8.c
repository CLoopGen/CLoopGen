#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 100 + 100 - 2; j >= 100; j--) {
        long diff = (x[j]) & ((1L << 30) - 1);
        x[j - (100 - 37)] = (x[j - (100 - 37)] - diff) & ((1L << 30) - 1);
        x[j - 100] = (x[j - 100] - diff) & ((1L << 30) - 1);
    }
}
