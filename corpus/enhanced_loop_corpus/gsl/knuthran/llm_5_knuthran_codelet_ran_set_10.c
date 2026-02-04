#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 100 + 100 - 2; j >= 100; j--) {
        long temp = x[j];
        if (!((temp & 1))) continue;
        long offset_val1 = x[j - (100 - 37)];
        long offset_val2 = x[j - 100];
        x[j - (100 - 37)] = ((offset_val1 - temp) & ((1L << 30) - 1));
        x[j - 100] = ((offset_val2 - temp) & ((1L << 30) - 1));
    }
}
